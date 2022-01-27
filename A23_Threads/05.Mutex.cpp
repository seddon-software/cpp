#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

/*  
 *  When two or more threads access shared data such as global or heap data there is a strong
 *  possibility that the data will be corrupted.  This happens when a thread performs a non atomic
 *  operation on data.  In fact most operations on data are not atomic.  For example adding 1 to a
 *  global variable x, involves storing the following instructions:
 *          LOAD R1, x
 *          INC R1
 *          STORE R1, x
 * 
 *  where R1 is a machine register.  When a thread is suspended by the kernel for the context switch
 *  the values of all registers used by the thread are paged out to disk.  If the thread get suspended
 *  before the value of R1 is stored in x then x can become corrupted.  This happens when another thread
 *  modifies the value of x and then later, our thread resumes.  Our thread will have its value of R1
 *  restored in the context switch, which although it was the value of x during our calculation, by now
 *  x has completely changed.  When we resume execution of this thread, it will update x with the value
 *  now in R1, which will overwrite the current value of x.  This will happen at random and can't be 
 *  predicted.
 * 
 *  To avoid data corruption problems we can use a mutex (mutually exclusive lock).  A mutex will
 *  ensure that only 1 thread can concurrently access a group of instructions.  Effectively this makes 
 *  the instructions atomic and ensures data corruption will not occur.
 * 
 *  We use the mutex as part of the RAII (Resource Acquisition Is Initialization) pattern.  We create
 *  a lock guard object which acquires the mutex lock in its constructor.  The lock is released in when
 *  the lock guard DTOR fires (when it goes out of scope).  You will see that only 1 thread at a time 
 *  executes the body of the lambda.
 */ 

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

