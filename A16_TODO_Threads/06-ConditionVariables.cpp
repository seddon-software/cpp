#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
using namespace std;


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

void go()
{
//    std::unique_lock<std::mutex> myLock(myMutex);
    ready = true;
    cv.notify_all();
}

int main ()
{
	using namespace std::literals::chrono_literals;

	// spawn 10 threads:
    thread threads[10];
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_id, i);

    // wait for 5 seconds so that threads have a chance to start and reach the cv barrier
    std::this_thread::sleep_for(5s);		// C++14

    // set the condition variable
    go();

    // wait for threads to complete
    for (auto& th : threads) th.join();
}
