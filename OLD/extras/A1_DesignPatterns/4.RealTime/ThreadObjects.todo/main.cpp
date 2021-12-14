#include <windows.h>
#include <iostream>
#include "thread.h"
using namespace std;


class myThread : public thread
{
public:
	myThread(char c) : ch(c) {}
protected:
	int run();
private:
	char ch;
};

int myThread::run()
{
    for(int i = 0; i < 100; ++i)
    {
		cout << ch;
    }

    MessageBoxA(0, "Exit?", "Thread",MB_OK);
    return 0;
}

DWORD WINAPI thread::workerThread(LPVOID lpParam)
{
   thread& _this = *(reinterpret_cast<thread*>(lpParam));  // recast this
   DWORD dwReturn = _this.run();		   // call polymorphic run
   return dwReturn;
}



int main()
{
	myThread t1('1');
	myThread t2('2');
	myThread t3('3');

	t1.start();
	t2.start();
	t3.start();

    MessageBoxA(0, "Exit?", "Main", MB_OK);
}
