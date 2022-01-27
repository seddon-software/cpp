#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

/*
 *  As a further example of locking, consider the two global counts in this example.  "count2" is protected
 *  by a lock guard, but "count1" is not.  The ++ operator is not an atomic operation and therefore we
 *  may experience data corruption when "count1" is incremented.  "count2" is safe because concurrent
 *  access is prevented by the lock guard.
 * 
 *  The probability of ++ being interrupted is very small, but not zero, so we need to perform many
 *  increments to illustrate the problem.  Even then we are no guaranteed that a corruption will occur.
 *  The program uses 4 threads to ncrement both counts 1,000,000 times, so the expected result should be
 *  4,000,000.  Run the program several times and you should see "count1" not reach this figure.
 */
 
mutex theMutex;

int count1 = 0;		// not protected
int count2 = 0;		// protected

void f()
{
	for(auto i = 0; i < 1000*1000; i++)
	{
		count1++;
	}

	std::lock_guard<mutex> theGuard(theMutex);
	for(auto i = 0; i < 1000*1000; i++)
	{
		count2++;
	}
}



int main()
{
    std::thread t1(f);
    std::thread t2(f);
    std::thread t3(f);
    std::thread t4(f);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    cout << "count1 = " << count1 << endl;
    cout << "count2 = " << count2 << endl;
}

