#include <iostream>
#include <thread>
using namespace std;

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

