////////////////////////////////////////////////////////////
//
//		Threads
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <exception>
#define BOOST_THREAD_USE_LIB
#include <boost/thread.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_smallint.hpp>
using namespace std;


// random numbers
boost::mt19937 gen;		// mersenne twister generator
boost::uniform_smallint<> dist(1, 100);	// range 1 ... 100

//threads call back on operator() method
class MyClass
{
public:
	MyClass(string s0) : s(s0) {}
	virtual ~MyClass() {}

	void operator() ()
	{
		for(int i = 1; i <= 25; i++)
		{
			cout << s;
			try
			{
				// random delay (1 ... 100 msec)
				int delay = dist(gen);
				boost::this_thread::sleep(boost::posix_time::milliseconds(delay));
			}
			catch(const exception& e)
			{
				cout << "Bad boy" << endl;
			}
		}
	}
private:
  	string s;
};

int main()
{
    // Create 4 objects
    MyClass m1("1");
    MyClass m2("2");
    MyClass m3("3");
    MyClass m4("4");

    // Create 4 thread objects
    // passing a reference to our objects
    // and start each thread
    boost::thread mythread1(m1);
    boost::thread mythread2(m2);
    boost::thread mythread3(m3);
    boost::thread mythread4(m4);

    mythread1.join();
    mythread2.join();
    mythread3.join();
    mythread4.join();
}


