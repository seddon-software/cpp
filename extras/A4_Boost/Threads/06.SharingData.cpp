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



int count1;
int count2;
boost::mutex myMutex;


void incrementCounts()
{
	for(int i = 0; i < 1000 * 1000; i++)
	{
		// protect count1, but not count2
		myMutex.lock();
		count1++;
		myMutex.unlock();
		count2++;
	}
}


int main()
{
	boost::thread myThread1(&incrementCounts);
	boost::thread myThread2(&incrementCounts);
	boost::thread myThread3(&incrementCounts);
	boost::thread myThread4(&incrementCounts);

	myThread1.join();
	myThread2.join();
	myThread3.join();
	myThread4.join();

	cout << "count1 =" << count1 << endl;	// should becorrect
	cout << "count2 =" << count2 << endl;   // may be incorrect

	return 0;
}


