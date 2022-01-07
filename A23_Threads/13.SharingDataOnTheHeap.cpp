#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex theMutex;


int main()
{
	// set up a buffer of ints on the heap
	const int size = 10;
	int* buffer = new int[size];
	for(int i = 0; i < 10; i++) buffer[i] = 0;

	// task to loop 1,000,000 times, adding to each element of buffer
	auto task = [buffer]()
		{
			for(int i = 0; i < 1000 * 1000; i++)
			{
				std::lock_guard<mutex> theGuard(theMutex);
				for(int i = 0; i < size; i++) buffer[i] += 1;
			}
		};

	// each thread performs the same task
	std::thread t1(task);
	std::thread t2(task);
	std::thread t3(task);
	std::thread t4(task);

	// wait for completion
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // print results and exit
	for(int i = 0; i < 10; i++) cout << buffer[i] << endl;
    delete[] buffer;
}

