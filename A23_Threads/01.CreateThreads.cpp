#include <iostream>
#include <thread>
using namespace std;
/*
 *  Threads are a mechanism for running code concurrently.  In the past this was achieved by using 
 *  separate processes and relying on the kernel to schedule the processes concurrently.  Although
 *  using seperate processes works, it turns out that the kernel has to spend a considerable time
 *  on the so called "context switch" whereby pages are paged in and out to disk as part of the
 *  virtual memory scheme.  Threads are an improvement on processes, because they all run within the
 *  same process and this in turn reduces the overhead on the "context switch".  The kernel still 
 *  performs scheduling of the threads, but the "context switch" is much faster, leading to more 
 *  efficient code.
 *  
 *  An alternative to threads is to use coroutines as these can run in the same thread, thereby
 *  eliminating the "context switch" entirely.  However, coroutines are still poorly supported and
 *  using threads is still highly popular.
 * 
 *  Every process begin execution with a single thread, essentially with "main" as its entry point;
 *  sometimes this first thread is called the main thread because of this.  However it is important
 *  to realise that the main thread is not special and executes code in the same way as any other 
 *  thread.
 * 
 *  Nearly all C and C++ programs utilise the C Runtime library and this library usually adds some
 *  code to add an abrupt process termination at the end of main.  So to avoid threads being killed
 *  prematurely, the main thread usually waits for the other threads to finish before exiting.  You
 *  can see this in the example below where main use the "join" method (so called because the time 
 *  lines are joined):
 * 	        t1.join(); // wait for thread to complete
 *
 *  Each thread can execute code, but it doesn't have to be the same code as in the main thread.  
 *  Indeed it is usual for a thread to execute different code and have a different entry point from 
 *  main.  Each thread will perform a unit of work, defined as a the thread function.  When the thread
 *  function ends, the thread exits.  Obviously, the thread function can call other functions and 
 *  thereby perform a lot of work if you so desire.
 * 
 *  The important part of this code is in main:
 *          std::thread t1(thread_function);
 * 
 *  t1 is a thread object; it is not a thread itself, rather a helper object.  
 * 
 *  The thread constructor contains code to tell the kernel to actually instantiate a new "worker"
 *  thread and  start scheduling it.  Note that the constructor contains a function pointer - this is 
 *  the entry point for the worker thread.  After the new thread is created it is not possible to 
 *  predict which of the two threads will be executing at any time in the future.  The kernel will 
 *  arrange for the threads to time slice on a single CPU machine, but may run the threads concurrently
 *  on different CPUs on a multi-core machine.  In either case the threads give the appearance of 
 *  concurrent execution.	
 */

// entry point for thread
void thread_function()
{
	// check thread id
	cout << "thread id: " << this_thread::get_id() << endl;
	std::cout << "Hello from the thread" << std::endl;
}

int main()
{
	// check thread id
	cout << "thread id: " << this_thread::get_id() << endl;
	// create and start a thread to execute the function
	std::thread t1(thread_function);
	std::cout << "Hello world\n";
	t1.join(); // wait for thread to complete
}

