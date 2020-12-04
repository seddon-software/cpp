////////////////////////////////////////////////////////////
//
//		Threads
//
////////////////////////////////////////////////////////////

#include <iostream>
#define BOOST_THREAD_USE_LIB
#include <boost/thread.hpp>
using namespace std;


void hello()
{
	cout << "Hello world, I'm a thread!" << endl;
}

int main()
{
  boost::thread mythread(&hello);
  mythread.join();
  return 0;
}
