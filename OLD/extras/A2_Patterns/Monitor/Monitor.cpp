////////////////////////////////////////////////////////////
//
//      Monitor
//
////////////////////////////////////////////////////////////

#include "thread.h"
#include "lock.h"
#include <iostream>
#include <string>
using namespace std;

// this class provides its own locking when used in 
// a synchronized block and is exception safe, because
// its locks use RAII
class MyMonitor : public Lock 
{
public:
	MyMonitor() : x(0) {}
	void Increment() { x++; }
	void Print() { wcout << x << " "; }
private:
	int x;
};



class MyThread : public thread
{
public:
	MyThread(wstring id, MyMonitor& m) : id(id), monitor(m) {}

	int run()
	{
		synchronized(monitor)
		{
			for(int i = 0; i < 25; i++)
			{
				Sleep(100);
				monitor.Increment();
				wcout << id;
			}
		}
		return 0;
	}

private:
	wstring id;
	MyMonitor& monitor;
};


int main()
{
	MyMonitor lock1, lock2, lock3, lock4;
	MyThread t1(L"1", lock1);
	MyThread t2(L"2", lock1);
	MyThread t3(L"3", lock1);
	MyThread t4(L"4", lock1);

	t1.start();
	t2.start();
	t3.start();
	t4.start();

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	wcout << endl << "counts are: " << endl;
	lock1.Print();
	lock2.Print();
	lock3.Print();
	lock4.Print();
}
