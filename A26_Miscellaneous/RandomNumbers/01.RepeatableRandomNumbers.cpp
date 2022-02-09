#include <random>
#include <iostream>
using namespace std;

/*
 *  We can use code from <random> to generate better sequences of psuedo random numbers than the older
 *  rand and srand functions.  These new algorithms are explained on the cppreference.com site.
 * 
 *  std::std::default_random_engine picks a psuedo random number generator that is implementation
 *  dependent.  Full details are on cppreference.com.
 *  
 *  Because we are using a psuedo random number generator and not seeding it, we produce a repeatable
 *  set of numbers on each run of the program.
 */ 

int rollDie()
{
	// engine and distribution must be static (only one allowed per program!)
	static std::default_random_engine engine{};
	static std::uniform_int_distribution<int> distribution{1, 6};   // range 1 .. 6
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

