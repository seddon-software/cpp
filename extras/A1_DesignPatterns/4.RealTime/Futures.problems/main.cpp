#include <windows.h>
#include <iostream>
#include <string>
#include "thread.h"
using namespace std;


Barrier barrier(3);


class myThread : public thread
{
public:
	myThread(string t) : id(t) {}
protected:
	int run();
private:
	string id;
};

int myThread::run()
{
	string title = "Thread" + id;

	MessageBox(0, "Started", title.c_str(), MB_OK);
	barrier.await();
	MessageBox(0, "Passed through barrier", title.c_str(), MB_OK);

    for(int i = 0; i < 100; ++i)
    {
		cout << id.c_str();
    }

	MessageBox(0, "Exit?", title.c_str(), MB_OK);
    return 0;
}




int main()
{
	myThread t1("1");
	myThread t2("2");
	myThread t3("3");

	t1.start();
	t2.start();
	t3.start();

	t1.join();
	t2.join();
	t3.join();
}
