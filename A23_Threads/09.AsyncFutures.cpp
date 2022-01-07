#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

int f(int lo, int hi)
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
	auto answer1 = async(f, 1, 10);
	auto answer2 = async(f, 11, 40);
	auto answer3 = async(f, 41, 100);
	auto answer = answer1.get() + answer2.get() + answer3.get();
	cout << "Got answer: " << answer << endl;
}

