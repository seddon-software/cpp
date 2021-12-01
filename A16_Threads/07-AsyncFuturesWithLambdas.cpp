#include <thread>
#include <iostream>
#include <future>
#include <chrono>

int fetch_int(int lo, int hi)
{
	int sum = 0;
	for (int i = lo; i < hi; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		sum += i*i;
	}
	return sum;
}

int main()
{	
	// future from an async()
	std::future<int> answer1 = std::async([]{ return fetch_int(1, 10); });
	std::future<int> answer2 = std::async([]{ return fetch_int(11, 40); });
	std::future<int> answer3 = std::async([]{ return fetch_int(41, 100); });
	std::cout << "Got answer: " << (answer1.get() + answer2.get() + answer3.get()) << std::endl;
}
