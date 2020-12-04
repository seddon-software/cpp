#include <windows.h>
#include <iostream>
#include <string>
#include "thread.h"
#include "latch.h"
using namespace std;

CountDownLatch latch(3);




class myThread : public thread
{
public:
	myThread(wstring t) : id(t) {}
protected:
	int run();
private:
	wstring id;
};

int main()
{
	myThread t1(L"1");
	myThread t2(L"2");
	myThread t3(L"3");

	t1.start();
	t2.start();
	t3.start();

    MessageBoxW(0, L"Release Latch?", L"Main", MB_OK);
	latch.release();

	t1.join();
	t2.join();
	t3.join();
}



int myThread::run()
{
	wstring title = L"Thread" + id;

	MessageBoxW(0, L"Started", title.c_str(), MB_OK);
	latch.acquire();
	MessageBoxW(0, L"Latch Acquired", title.c_str(), MB_OK);

    for(int i = 0; i < 100; ++i)
    {
		wcout << id.c_str();
    }

	MessageBoxW(0, L"Exit?", title.c_str(), MB_OK);
    return 0;
}




