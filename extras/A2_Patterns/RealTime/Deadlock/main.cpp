#include <windows.h>
#include <iostream>
#include <string>
#include "thread.h"
#include "mutex.h"
using namespace std;


class MyThread : public thread
{
public:
	MyThread(string t) : id(t) {}
protected:
	void Display(string message, string title)
	{
		MessageBox(0, message.c_str(), title.c_str(), MB_OK|MB_ICONINFORMATION);
	}
	void GetMutex(HANDLE hMutex, string number)
	{
		cout << endl << id << " waiting for Mutex " << number << endl;
		WaitForSingleObject(hMutex, INFINITE);
		Display(string("Acquired Mutex") + number.c_str(), id);
		cout << endl << id << " got Mutex " << number << endl;
	}
	void ReleaseMutexes()
	{
		ReleaseMutex(hMutex1);
		ReleaseMutex(hMutex2);
		MessageBox(0, "Released Mutex 1 and 2", id.c_str(), MB_OK|MB_ICONINFORMATION);
	}
	string id;
};

class MyThread1 : public MyThread
{
public:
	MyThread1(string t) : MyThread(t) {}
protected:
	virtual int run()
	{
	    Display("Acquire Mutexes?", id);
		GetMutex(hMutex1, "1");
		GetMutex(hMutex2, "2");
		ReleaseMutexes();
		return 0;
	}
};

class MyThread2 : public MyThread
{
public:
	MyThread2(string t) : MyThread(t) {}
protected:
	virtual int run()
	{
	    Display("Acquire Mutexes?", id);
		GetMutex(hMutex2, "2");
		GetMutex(hMutex1, "1");
		ReleaseMutexes();
		return 0;
	}
};





int main()
{
    try
    {
        hMutex1 = CreateMutex("1");
        hMutex2 = CreateMutex("2");

	    MyThread1 t1("Thread 1");
	    MyThread2 t2("Thread 2");

		t1.start();
		t2.start();

		t1.join();
		t2.join();
    }
    catch(char* message)
    {
        cout << message << endl;
    }
}
