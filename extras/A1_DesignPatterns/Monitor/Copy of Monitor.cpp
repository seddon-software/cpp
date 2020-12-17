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
    Lock()
    {
        InitializeCriticalSection(&cs);
    }
    void lock()
    {
        //EnterCriticalSection(&cs);
    }
    void unlock()
    {
        //LeaveCriticalSection(&cs);
    }
private:
    CRITICAL_SECTION cs;
};

class Resource
{
public:
    void Update();
private:
    int x;
    int y;
private:
    void DoUpdate();
    void RestartWaitingThreadsAndUnlock();
    void UnlockRestartWaitingThreadsAndSuspend();
    deque<HANDLE> suspendedThreads;
    Lock monitor;
};

void Resource::Update()
{
    while(true)
    {
        monitor.lock();
        int x = MessageBox(0, L"Block?", L"Thread", MB_OKCANCEL);
        //::MB_DEFBUTTON1;
        if(x == 1) cout << "OK";
        x++;
        x--;
        x--;
    }
}

void Resource::DoUpdate()
{
    x++;
    y++;
}

void Resource::UnlockRestartWaitingThreadsAndSuspend()
{
    if(!suspendedThreads.empty())
    {
        HANDLE hSuspendedThread = suspendedThreads.front();
        suspendedThreads.pop_front();
        ResumeThread(hSuspendedThread);
    }
    suspendedThreads.push_back(GetCurrentThreadHandle());
    monitor.unlock();
    SuspendThread(GetCurrentThreadHandle());
}

void Resource::RestartWaitingThreadsAndUnlock()
{
    if(!suspendedThreads.empty())
    {
        HANDLE hSuspendedThread = suspendedThreads.front();
        suspendedThreads.pop_front();
        ResumeThread(hSuspendedThread);
    }
    monitor.unlock();
}

////////////////////////////////////////////////////////////

void MyThread(void* v)
{
    Resource& resource = *(Resource*) v;
    resource.Update();
}

int main()
{
    Resource resource;
    _beginthread(MyThread, 8192, &resource);
    //_beginthread(MyThread, 8192, &resource);
    //_beginthread(MyThread, 8192, &resource);
    //_beginthread(MyThread, 8192, &resource);
    MessageBox(0, L"Exit?", L"Main Thread", MB_OK|MB_ICONINFORMATION);
}
