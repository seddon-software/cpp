#include <iostream>
using namespace std;

#include "mutex.h"
#include "thread.h"


int count1;
int count2;


class myThread : public thread
{
public:
	myThread(Mutex& m) : mutex(m) {}
	
	int run()
	{
		for(int i = 0; i < 1000 * 1000; i++)
		{
			mutex.lock();
			count1++;
			mutex.unlock();
			count2++;
		}
		return 0;
	}
private:
	Mutex& mutex;
};


int main()
{
	Mutex m;
	myThread t1(m), t2(m);
	t1.start();
	t2.start();
	t1.join();
	t2.join();

	cout << "count1: " << count1 << endl;
	cout << "count2: " << count2 << endl;
}

