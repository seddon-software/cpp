#include <iostream>
#include <thread>


// function to act as
void thread_function()
{
	std::cout << "Hello from the thread" << std::endl;
}

int main()
{
	// create and start a thread to execute the function
	std::thread t1(thread_function);
	std::cout << "Hello world\n";
	t1.join(); // wait for thread to complete
}

