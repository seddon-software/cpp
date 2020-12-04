#include "thread.h"
#include "lock.h"
#include <string>
using namespace std;


class MyThread : public thread
{
public:
	MyThread(HANDLE h, wstring t) : hMutex(h), title(t) {}

	int run()
	{
		MessageBoxW(0, L"Enter synchronized block?", title.c_str(), MB_OK);
		synchronized(hMutex)
		{
	        MessageBoxW(0, L"Leave synchronized block?", title.c_str(), MB_OK);
		}
	    MessageBoxW(0, L"Exit thread?", title.c_str(), MB_OK);
		return 0;
	}
private:
	wstring title;
	HANDLE hMutex;
};

int main()
{
	HANDLE h = Lock::Create();

	MyThread t1(h, L"Thread1");
	MyThread t2(h, L"Thread2");
	MyThread t3(h, L"Thread3");

	t1.start();
	t2.start();
	t3.start();

	t1.join();
	t2.join();
	t3.join();

	Lock::Destroy(h);
}
