#include <array>
#include <thread>
#include <mutex>
#include <string>
#include <iostream>
using namespace std;

// protecting data with a mutex

mutex myMutex;
struct data
{
	int a;
	int b;
};

data item1;		// not protected
data item2;		// protected

class MyThread
{
public:
	MyThread() {}

	void operator() ()
	{
		for(unsigned i = 0; i < 10 * 1000 * 1000; i++)
		{
			// item1 not protected
			item1.a++;
			item1.b++;
			lock_guard<mutex> guard(myMutex);  // use RAII to protect item2
			item2.a++;
			item2.b++;
		}
	}

	void start()
	{
		t = thread(MyThread());
	}
	void join()
	{
		t.join();
	}
private:
	thread t;		// thread is not started by default CTOR
};

int main()
{
	const int N = 50;		// number of threads
	array<MyThread,N> m;

	for(int i = 0; i < N; i++)
	{
		m[i].start();
	}

	for(int i = 0; i < N; i++)
	{
		m[i].join();
	}

	cout << "item1 = " << item1.a << "," << item1.b << endl;
	cout << "item2 = " << item2.a << "," << item2.b << endl;
}

