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

// local variable automatically destroyed on exit
#define synchronized(cs) for(Lock lock(cs); lock;)

class Lock
{
public:
    Lock(CRITICAL_SECTION& cs) : cs(cs)
    {
        flag1 = true;
        flag2 = false;
        EnterCriticalSection(&cs);
    }
    ~Lock()
    {
        LeaveCriticalSection(&cs);
    }
    operator bool() // ensure loop only iterates once
    {
        bool flag = flag1;
        flag1 = flag2;
        return flag;
    }
private:
    bool flag1;
    bool flag2;
    CRITICAL_SECTION& cs;
};

class Resource
{
public:
    Resource(CRITICAL_SECTION& cs, int x, int y) 
        : cs(cs), x(x), y(y) {}
    void Update();
    void Print();
private:
    int x;
    int y;
    CRITICAL_SECTION& cs;
};


void Resource::Update()
{
    synchronized(cs)
    {
        x++;
        y++;
    }
}

void Resource::Print()
{
    cout << "Result: " << x++ << "," << y++ << endl;
}


////////////////////////////////////////////////////////////

void MyThread(void* v)
{
    Resource& resource = *(Resource*) v;
    for(int i = 0; i < 1000 * 1000 * 10; i++)
    {
        resource.Update();
    }
    MessageBox(0, L"Exit?", L"Thread", MB_OK);
}


int main()
{
    CRITICAL_SECTION cs;
    InitializeCriticalSection(&cs);

    Resource resource(cs, 0,0);
    _beginthread(MyThread, 8192, &resource);
    _beginthread(MyThread, 8192, &resource);
    _beginthread(MyThread, 8192, &resource);
    _beginthread(MyThread, 8192, &resource);
    MessageBox(0, L"Exit?", L"Main Thread", MB_OK|MB_ICONINFORMATION);
    resource.Print();
}
