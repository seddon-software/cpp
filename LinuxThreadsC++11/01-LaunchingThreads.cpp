////////////////////////////////////////////////////////////
//
//		Launching Threads
//
////////////////////////////////////////////////////////////

// launch threads using thread CTOR that takes a functor as parameter

#include <thread>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:
	Worker(const string& id) : id(id) {}

	void operator()()
	{
		for(int i = 0; i < 25; i++)
		{
			std::chrono::milliseconds duration(rand() % 1000);
			std::this_thread::sleep_for(duration);
			cout << id;
			cout.flush();
		}
	}
private:
	string id;
};



int main() {
	Worker w1("1");
	Worker w2("2");
	Worker w3("3");
	Worker w4("4");

	// Launch threads using thread CTOR
	//	param1 = functor => operator()() will be called
	thread t1(w1);
	thread t2(w2);
	thread t3(w3);
	thread t4(w4);

    // wait for threads to finish
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}


