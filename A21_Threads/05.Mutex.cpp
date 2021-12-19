#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

mutex theMutex;

int main()
{
	auto mylambda = [](string id, int delay)
					{
						lock_guard<mutex> theGuard(theMutex);
						for(int i = 1; i <= 25; i++)
						{
							cout << id  << flush;
							this_thread::sleep_for(chrono::milliseconds(delay));
						}
					};

    thread t1(mylambda, "1", 100);
    thread t2(mylambda, "2", 140);
    thread t3(mylambda, "3", 180);
    thread t4(mylambda, "4", 220);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

