#include <windows.h>
#include <iostream>
using namespace std;

class thread
{
public:
	typedef LPTHREAD_START_ROUTINE functionPtr;
	thread(functionPtr, void*);
	void start();
    ~thread() {} // cleanup thread
private:
	HANDLE m_hThread;
};

thread::thread(functionPtr fp, void* param)
{
    DWORD dwThreadId = 0;
    m_hThread = CreateThread( NULL, 0, fp, (LPVOID) param,
                                CREATE_SUSPENDED, &dwThreadId);
}
void thread::start()
{
	ResumeThread(m_hThread);
}


DWORD WINAPI myThreadFunction(LPVOID lpParam)
{
    int ch = reinterpret_cast<int>(lpParam);

    for(int i = 0; i < 100; ++i)
    {
		cout << ch;
    }

    MessageBoxW(0, L"Exit?", L"Thread",MB_OK);
    return 0;
}


int main()
{
    char ch = 'a';
    thread t1(&myThreadFunction, reinterpret_cast<void*>(ch));

    char ch2 = 'b';
    thread t2(&myThreadFunction, reinterpret_cast<void*>(ch2));

    t1.start();
    t2.start();

    Sleep(1000);
    MessageBoxW(0, L"Exit?", L"Main",MB_OK);
    std::cout << "End of main" << std::endl;
}
