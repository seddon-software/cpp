////////////////////////////////////////////////////////////
//
//      Monitor
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <deque>
#include <windows.h>
#include <process.h>
using namespace std;


HANDLE GetCurrentThreadHandle()
{
    HANDLE handle;
    DWORD error = DuplicateHandle(
                GetCurrentProcess(), // source process
                GetCurrentThread(),  // handle to duplicate
                GetCurrentProcess(), // target process
                &handle,            // target handle
                0,
                0,
                DUPLICATE_SAME_ACCESS);
    if (error == 0) throw "Can't duplicate handle";
    return handle;
}


class Lock
{
public:
    Lock(HANDLE hMutex) : hMutex(hMutex) {}

    void lock()
    {
        WaitForSingleObject(hMutex, INFINITE);
    }

    DWORD tryLock()
    {
        return WaitForSingleObject(hMutex, 10);
    }

    void unlock()
    {
        ReleaseMutex(hMutex);
    }
private:
    HANDLE hMutex;
};

class Resource
{
public:
    enum { max = 6 };
    Resource(Lock& monitor) 
        : monitor(monitor), suspendedThread(0) {}
    bool isFull();
    bool isEmpty();
    int Get();
    void Put(int x);
    void Print();
private:
    void wait();
    void notify();
    deque<int> q;
    HANDLE suspendedThread;
    Lock& monitor;
};

bool Resource::isFull()
{
    return q.size() >= max;
}

bool Resource::isEmpty()
{
    return q.empty();
}

int Resource::Get()
{
    int x;
    monitor.lock();

    while(isEmpty()) 
    {
        wait();
    }
    x = q.back();
    q.pop_back();

    monitor.unlock();
    notify();
    return x;
}

void Resource::Put(int x)
{
    monitor.lock();

    while(isFull()) 
    {
        wait();
    }
    q.push_front(x);
    monitor.unlock();
    notify();
}

void Resource::Print()
{
    monitor.lock();
    deque<int>::iterator i;
    for(i = q.begin(); i != q.end(); i++)
    {
        cout << *i << ",";
        ++i;
    }
    cout << endl;
    monitor.unlock();
}

void Resource::notify()
{
    if(suspendedThread != 0)
    {
        ResumeThread(suspendedThread);
    }
}

void Resource::wait()
{
    monitor.unlock();

    // resume other thread if it is suspended
    if(suspendedThread != 0)
    {
        ResumeThread(suspendedThread);
    }

    suspendedThread = GetCurrentThreadHandle();
    SuspendThread(suspendedThread);
    // we are now suspended
    // another thread must wake us 
    // try to acquire the lock
    
    monitor.lock();
}

////////////////////////////////////////////////////////////

void Producer(void* v)
{
    Resource& resource = *(Resource*) v;
    for(int i = 0; i < 100; i++)
    {
        cout << "Put: " << i << endl;
        resource.Put(i);
    }
    MessageBox(0, L"Exit?", L"Thread", MB_OK);
}

void Consumer(void* v)
{
    Resource& resource = *(Resource*) v;
    for(int i = 0; i < 100; i++)
    {
        cout << "Get: " << resource.Get() << endl;
        Sleep(100);
    }
    MessageBox(0, L"Exit?", L"Thread", MB_OK);
}


int main()
{
    HANDLE hMutex = CreateMutex(0, 0, 0);
    Lock monitor(hMutex);

    Resource resource(monitor);
    _beginthread(Producer, 8192, &resource);
    _beginthread(Consumer, 8192, &resource);

    MessageBox(0, L"Exit?", L"Main Thread", MB_OK|MB_ICONINFORMATION);
    resource.Print();
}
