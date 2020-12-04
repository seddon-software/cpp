#include <random>
#include <iostream>
using namespace std;


int rollDie()
{
	// engine and distribution must be static (only one!)
	static std::random_device rdev{};
	static std::default_random_engine engine{rdev()};
	static std::uniform_int_distribution<int> distribution{1, 6};
	return distribution(engine);
}

// This program always produces the same results
int main()
{
	for(int i = 0; i < 10; i++)
	{
		cout << rollDie() << endl;
	}
}

