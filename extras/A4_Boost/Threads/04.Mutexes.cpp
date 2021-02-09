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
	MyClass(string s0, boost::mutex& lock) : s(s0), myMutex(lock) {}
	virtual ~MyClass() {}


	void operator() ()
	{
		myMutex.lock();
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
		myMutex.unlock();
	}
	void start()
	{
		 myThread = boost::thread(&MyClass::operator(), this);
	}
	void join()
	{
		 myThread.join();
	}
private:
  	string s;
  	boost::thread myThread;
  	boost::mutex& myMutex;
};

int main()
{
	boost::mutex lock1;
	boost::mutex lock2;
	boost::mutex lock3;
	boost::mutex lock4;

    // Create 4 objects
    MyClass m1("1", lock1);
    MyClass m2("2", lock2);
    MyClass m3("3", lock3);
    MyClass m4("4", lock4);

    // Create 4 thread objects
    // passing a reference to our objects
    // and start each thread
    m1.start();
    m2.start();
    m3.start();
    m4.start();

    m1.join();
    m2.join();
    m3.join();
    m4.join();
}


