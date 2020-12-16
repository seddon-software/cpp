#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


void f(int d)
{
	d += 1;
}


void g(int& d)
{
	d += 1;
}


int main()
{
	int x = 100;

	std::thread t1(f, x);
    t1.join();
    cout << x << endl;

// You can't simply pass parameters to a thread by reference, because
// there is no guarantee your thread will be alive when the reference is used
// so the next line won't compile - use async instead
    // std::thread t2(g, x);

}

