#include <atomic>
#include <thread>
#include <string>
#include <iostream>
using namespace std;

// launch threads using thread CTOR that takes a functor plus one other parameter
// and use inheritance rather than composition

class MyThread : public thread
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
		thread* base = dynamic_cast<thread*>(this);  // get access to superclass
		MyThread x = MyThread();
		*base = thread(std::move(x), s);  // convert x into r-value ref
	}
	//	join method inherited from superclass
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

