#include <atomic>
#include <thread>
#include <string>
#include <iostream>
using namespace std;

// launch threads using thread CTOR that takes a functor plus one other parameter

class MyThread
{
public:
	MyThread() {}

	void operator() (const string& s)
	{
		for(int i = 0; i < 25; i++)
		{
			std::chrono::milliseconds duration(rand() % 1000);
			std::this_thread::sleep_for(duration);
			cout << s;
			cout.flush();
		}
	}

	void start(const string& s)
	{
		// thread CTOR: param-1 = temp functor,
		//              param-2 = parameters to pass to functor's operator()
		t = thread(MyThread(), s);  // create temp and use operator=(&&) to start thread
	}
	// alternative way of writing start()
	void start2(const string& s)
	{
		MyThread x = MyThread();
		t = thread(std::move(x), s);  // convert x into r-value ref
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
	MyThread m1;
	MyThread m2;
	MyThread m3;
	MyThread m4;
	m1.start("1");
	m2.start("2");
	m3.start("3");
	m4.start("4");
	m1.join();
	m2.join();
	m3.join();
	m4.join();
}

