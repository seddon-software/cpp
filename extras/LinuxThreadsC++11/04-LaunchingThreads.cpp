#include <atomic>
#include <thread>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// example passing arbitary parameters to thread (by value)

class MyThread
{
public:
	MyThread() {}

	void operator() (int& n, const string& s, vector<double>& v)
	{
		for(unsigned i = 0; i < v.size(); i++)
		{
			cout << v[i] << ",";
		}
		cout << endl;
		for(int i = 0; i < n; i++)
		{
			std::chrono::milliseconds  duration(rand() % 1000);
			std::this_thread::sleep_for(duration);
			cout << s;
			cout.flush();
		}
	}

	void start(int n, const string& s, const vector<double>& v)
	{
		t = thread(MyThread(), n, s, v);
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
	vector<double> v1 = {1.1,1.2,1.3};
	vector<double> v2 = {2.1,2.2,2.3};
	vector<double> v3 = {3.1,3.2,3.3};
	vector<double> v4 = {4.1,4.2,4.3};
	m1.start(10, "1", v1);
	m2.start(20, "2", v2);
	m3.start(30, "3", v3);
	m4.start(40, "4", v4);
	m1.join();
	m2.join();
	m3.join();
	m4.join();
}

