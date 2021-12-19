#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>
#include <chrono>
#include <random>
using namespace std;


void do_work(string id, int delay)
{
	for(int i = 1; i <= 25; i++)
	{
		unsigned seed = chrono::system_clock::now().time_since_epoch().count();
		minstd_rand0 generator{seed};  // minstd_rand0 is a standard linear_congruential_engine
		cout << id  << flush;
		delay = generator() % 1000;
		this_thread::sleep_for(chrono::milliseconds(delay));
	}
}

int main()
{
	// lock_guard uses RAAI (lock in CTOR, unlock in DTOR) 
	mutex m1;
	mutex m2;
	mutex m3;
	mutex m4;

	[[maybe_unused]]
	auto lambda1 = [&m1](string id, int delay)
					{
						lock_guard theGuard(m1); // RAAI
						do_work(id, delay);
					};
	[[maybe_unused]]
	auto lambda2 = [&m2](string id, int delay)
					{
						lock_guard theGuard(m2); // RAAI
						do_work(id, delay);
					};
	[[maybe_unused]]
	auto lambda3 = [&m3](string id, int delay)
					{
						lock_guard theGuard(m3); // RAAI
						do_work(id, delay);
					};
	[[maybe_unused]]
	auto lambda4 = [&m4](string id, int delay)
					{
						lock_guard theGuard(m4); // RAAI
						do_work(id, delay);
					};
	// try changing the lambdas below
    std::thread t1(lambda1, "1", 100);
    std::thread t2(lambda2, "2", 140);
    std::thread t3(lambda1, "3", 180);
    std::thread t4(lambda2, "4", 220);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

