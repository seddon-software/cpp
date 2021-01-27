#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex theMutex;

struct MyClass
{
	void operator()(string id, int delay)
	{
		theMutex.lock(); // or, to be exception-safe, use std::lock_guard
	    for(int i = 1; i <= 25; i++)
	    {
	    		cout << id  << flush;
	        std::this_thread::sleep_for(
	        		std::chrono::milliseconds(delay)
	        );
	    }
	    theMutex.unlock();
	}
};



int main()
{
    std::thread t1(MyClass(), "1", 100);
    std::thread t2(MyClass(), "2", 140);
    std::thread t3(MyClass(), "3", 180);
    std::thread t4(MyClass(), "4", 220);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

