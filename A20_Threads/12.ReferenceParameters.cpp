#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


/* 
 *  We saw earlier that threads can use lambdas to capture stack based variables from another thread.
 *  We can also pass additional parameters to the thread constructor.  However, in general, threads
 *  do NOT share stack storage, which makes it difficult to share state between threads.
 * 
 *  Recall, threads DO share global variables and heap space, but using stack based variables would be 
 *  more convenient. 
 *  
 *  The real problem with stack based variables is that you can't simply pass parameters to a thread 
 *  function by reference, because there is no guarantee that your thread will be alive when the 
 *  reference is used.  Remember, the additional parameters to the thread constructor are passed to 
 *  the thread function.  Thus
 *          thread t1(f, x);  // a copy of x is passed to the thread
 *
 *  starts the thread function as f(x).  The function f is declared to take a value parameter, so the
 *  compiler is happy with that.  If we try:
 *          thread t2(g, x);
 *  
 *  this will fail to compile because g is declared to take a reference parameter and this might cause
 *  problems if x dies before it is used.
 * 
 *  If you really want to pass by reference and you must add code to ensure x will be alive when it is 
 *  used and you can inform the compiler that it is safe to pass by reference using std::ref as in:
 *           thread t3(g, std::ref(x));  
 *
 *  In general it is better to use async futures to pass state between threads.
 */

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
    thread t3(g, std::ref(x));  
	// std::ref lets you pass by reference, but its your responsibility to ensure x is alive 
	// when the thread executes
	t3.join(); // ensure x is alive when thread executes
    cout << x << endl;
}

