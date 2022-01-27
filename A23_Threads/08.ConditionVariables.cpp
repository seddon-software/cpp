#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std;

/*
 *  Condition variables are objects able to block the calling thread until it is notified to resume.  The 
 *  condition variable uses a mutex to lock the thread when one of its wait functions is called.  The 
 *  thread remains blocked until woken up by another thread.
 * 
 *  You can think of condition variables as a red flag that stops threads in their tracks when the flag is
 *  raised.  Any number of threads can be waiting on the flag.  Some other thread can then lower the flag 
 *  to release all the waiting threads simultaneously.
 * 
 *  Here, the main thread creates 10 worker threads that wait on a condition variable (which is dependent
 *  on a common mutex).  The main thread waits 5 seconds and then uses "notify_all" to release all the
 *  waiting threads. 
 */

std::mutex myMutex;
std::condition_variable cv;
bool ready = false;

void print_id(int id)
{
	// several threads will try to print at the same time
	// and this line is not protected by a lock and hence
	// this line is not thread safe !!!!
	cout << "thread " << id << " started" << endl;

	std::unique_lock<std::mutex> myLock(myMutex);
	cout << "thread " << id << " executing" << endl;

    while (!ready) cv.wait(myLock);
    cout << "thread " << id << " completed" << endl;
}

int main ()
{
	using namespace std::literals::chrono_literals;  // so we can use 5s as 5 seconds

	// spawn 10 threads:
    thread threads[10];
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_id, i);

    // wait for 5 seconds so that threads have a chance to start and reach the cv barrier
    std::this_thread::sleep_for(5s);		// C++14

    // set the condition variable
    cv.notify_all();

    // wait for threads to complete
    for (auto& th : threads) th.join();
}
