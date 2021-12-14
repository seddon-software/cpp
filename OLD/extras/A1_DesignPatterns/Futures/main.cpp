#include <windows.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "thread.h"
#include "futures.h"
using namespace std;

typedef int (*FP)(int low, int high);

class myThread : public thread
{
public:
	myThread(FP fp, int low, int high) 
        : low(low), high(high), fp(fp) {}
protected:
	int run();
private:
    int low;
    int high;
    FP fp;
};

int myThread::run()
{
    int result = fp(low, high);
    stringstream s;
    s << result;
    MessageBoxA(0, s.str().c_str(), "Thread", MB_OK);
    return result;
}

DWORD WINAPI thread::workerThread(LPVOID lpParam)
{
   thread& _this = *(reinterpret_cast<thread*>(lpParam));  // recast this
   DWORD dwReturn = _this.run();		   // call polymorphic run
   return dwReturn;
}

int squares(int low, int high)
{
    int result = 0;
    for(int i = low; i <= high; i++)
    {
        result += i * i;
    }
    return result;
}


int main()
{
    myThread t1(squares, 1, 2);
    myThread t2(squares, 3, 4);
    myThread t3(squares, 5, 6);

    Futures futures;
    futures.request(&t1);
    futures.request(&t2);
    futures.request(&t3);
    futures.start();

    stringstream result;
    result << futures.getResult();

    MessageBoxA(0, result.str().c_str(), "Main", MB_OK);
}
