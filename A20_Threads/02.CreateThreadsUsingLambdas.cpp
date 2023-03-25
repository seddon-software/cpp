#include <iostream>
#include <thread>
using namespace std;

/*  
 *  Specification of the thread function in the thread constructor can be achieved using a lambda
 *  as in this example.  Each thread maintains a private stack Iincluding the main thread), which means
 *  a thread's local variables are private within a thread.  By using a lambda you can capture local 
 *  variables from the main thread (by value or by reference).
 * 
 *  Note that although threads have a private stack, the heap space and global variables are shared
 *  between all the threads (hence the reduced context switch).  Certain kernel stuctures are shared 
 *  across all the threads and some are private to individual threads.
 * 
 *  The example shows how a thread can use capture by reference to modify the local variables in the main
 *  thread.  
 * 
 *  Interestingly, both the main thread and the worker thread use the iostream library.  By
 *  calling join before using cout, the main thread ensures that the two threads don't access cout at
 *  the same time.  It turns out that the iostream code is not thread safe; if you remove the comment
 *  in the code below to allow both threads to access cout concurrently, output may become garbled.  
 *  However, this is highly dependent on scheduling, so you might need to run the code more than once 
 *  for it to go wrong.
 */

int main()
{
	int x = 5;
	int y = 8;
    thread myThread(
    	[&x, &y]()  // capture by reference
		{
			cout << "Hello from the thread" << endl;
			x *= 2; y*= 2;
			cout << "Thread: x = " << x << ",y = " << y << endl;
		}
	);
	// uncomment to see unsynchronized behaviour
	// cout << "Main: x = " << x << ",y = " << y << endl;
    myThread.join();  // synchronize to ensure references are alive in thread code
	cout << "Main: x = " << x << ",y = " << y << endl;
}
