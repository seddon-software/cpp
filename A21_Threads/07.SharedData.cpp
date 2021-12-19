#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

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

