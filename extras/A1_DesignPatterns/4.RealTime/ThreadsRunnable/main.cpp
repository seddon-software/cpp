#include <windows.h>
#include <iostream>
#include <string>
#include "runnable.h"
#include "thread.h"
using namespace std;


class myClass : public dp::runnable
{
public:
	myClass(string t) : id(t) {}
	virtual int run();
private:
	string id;
};

int myClass::run()
{
    for(int i = 0; i < 100; ++i)
    {
		cout << id;
		Sleep(10);
    }

	string title = "Thread" + id;
	MessageBox(0, "Exit?", title.c_str(), MB_OK);

	return 0;
}

int main()
{
	myClass m1("1");	// supports runnable
	myClass m2("2");
	myClass m3("3");
	
	dp::thread t1(m1);
	dp::thread t2(m2);
	dp::thread t3(m3);

	t1.start();
	t2.start();
	t3.start();

	t1.join();
	t2.join();
	t3.join();
}
