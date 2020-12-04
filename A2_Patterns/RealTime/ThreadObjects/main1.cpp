#include <windows.h>
#include <iostream>
#include <string>
#include "thread.h"
using namespace std;


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
    for(int i = 0; i < 100; ++i)
    {
		wcout << id.c_str();
    }

	wstring title = L"Thread" + id;
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
//    MessageBox(0, L"Exit?", L"Main", MB_OK);
}
