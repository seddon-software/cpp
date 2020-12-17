#include <windows.h>
#include <iostream>
#include <string>
#include "thread.h"
#include "barrier.h"
using namespace std;


Barrier barrier(3);


class myThread : public thread
{
public:
	myThread(wstring t) : id(t) {}
protected:
	int run();
private:
	wstring id;
};

int myThread::run()
{
	wstring title = L"Thread" + id;

	MessageBoxW(0, L"Started", title.c_str(), MB_OK);
	barrier.await();
	MessageBoxW(0, L"Passed through barrier", title.c_str(), MB_OK);

    for(int i = 0; i < 100; ++i)
    {
		wcout << id.c_str();
    }

	MessageBoxW(0, L"Exit?", title.c_str(), MB_OK);
    return 0;
}




int main()
{
	myThread t1(L"1");
	myThread t2(L"2");
	myThread t3(L"3");

	t1.start();
	t2.start();
	t3.start();

	t1.join();
	t2.join();
	t3.join();
}
