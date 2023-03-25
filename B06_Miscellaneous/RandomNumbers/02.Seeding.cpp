#include <random>
#include <iostream>
using namespace std;

/*
 *  We can use code from <random> to generate better sequences of psuedo random numbers than the older
 *  rand and srand functions.  These new algorithms are explained on the cppreference.com site.
 * 
 *  std::random_device is a uniformly-distributed integer random number generator that produces 
 *  non-deterministic random numbers (some implementations may be psuedo random).  The algorithm may
 *  be slow and therefore it should be used to generate a seed for an alternative pseudo-random number 
 *  engine.
 *  
 *  Unlike the previous example, we seed the psuedo random mumber generator with a random seed and hence
 *  the numbers generated are not repeatable.
 */ 

int rollDie()
{
	// engine and distribution must be static (only one!)
	static std::random_device rdev{};
    auto seed = rdev();
	static std::default_random_engine engine{seed};
	static std::uniform_int_distribution<int> distribution{1, 6};
	return distribution(engine);
}

// This program always produces the same results
int main()
{
	for(int i = 0; i < 10; i++)
	{
		cout << rollDie() << ", ";
	}
    cout << endl;
}

