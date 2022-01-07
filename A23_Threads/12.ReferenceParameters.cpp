#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


void f(int d)
{
	d += 1;  // increment a copy of d
}


void g(int& d)
{
	d += 1;  // increment original
}


int main()
{
	int x = 100;

	thread t1(f, x);  // a copy of x is passed to the thread
	t1.join();
    cout << x << endl;

// You can't simply pass parameters to a thread by reference, because
// there is no guarantee your thread will be alive (the thread declaring x) when the reference is used
// so the next line won't compile - use std::ref or async or lambdas instead (see later examples)
    // thread t2(g, x);
    thread t2(g, std::ref(x));  
	// std::ref lets you pass by reference, but its your responsibility to ensure x is alive 
	// when the thread executes
	t2.join(); // ensure x is alive when thread executes
    cout << x << endl;
}

