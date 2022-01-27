#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

/*
 *  You can get threads to coordinate on performing a calculation.  However, synchronizing between 
 *  the threads can be tricky, so aysnc futures were introduced to simply such code.
 * 
 *  In this example we calculate the sum of squares for the first 100 integers.  To speed up the 
 *  calculation, we use 3 separate threads to share this calculation.  The async function defined 
 *  in the <future> header file creates a new thread that runs asyncronously with the calling thread.
 * 
 *  async takes a function pointer and any number of additional parameters.  The function pointer
 *  becomes the thread's entry point.  When the thread completes, it stores its return value in some
 *  compiler allocated storage.  The result can be retrieved by any thread using the get() method;
 *  the compiler will clean up the allocated storage automatically.  
 * 
 *  I've added a small delay to each sub-calculation to simulate a more lengthy calculation.
 */

int f(int lo, int hi)
{
	int sum = 0;
	for (int i = lo; i < hi; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		sum += i*i;
	}
	return sum;
}

int main()
{
	auto answer1 = async(f, 1, 10);
	auto answer2 = async(f, 11, 40);
	auto answer3 = async(f, 41, 100);
	auto answer = answer1.get() + answer2.get() + answer3.get();
	cout << "Got answer: " << answer << endl;
}

