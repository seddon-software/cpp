#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <clocale>
using namespace std;

/*
 *  Random number engines generate pseudo-random numbers using seed data as entropy source. Several 
 *  different classes of pseudo-random number generation algorithms are implemented as templates 
 *  that can be customized.
 * 
 *  std::random_device is a uniformly-distributed integer random number generator that produces 
 *  non-deterministic random numbers (some implementations may be psuedo random).  The algorithm may
 *  be slow and therefore it should be used to generate a seed for an alternative pseudo-random number 
 *  engine. 
 * 
 *  std::default_random_engine picks a pseudo-random number engine from a number of alternatives (see
 *  cppreference.com).  We seed it with an integer from a std::random_device object.
 */


int main()
{
// setup engine
	static std::random_device rdev{};
	static std::default_random_engine engine{rdev()};

// Manufacture a deck of cards:
	using card = int;
	std::array<card, 52> deck{};                // create an array 52 elements in size
	std::iota(deck.begin(), deck.end(), 0);     // fill with integers 0, 1, 2 ... 51

// Shuffle the deck:
	std::shuffle(deck.begin(), deck.end(), engine);

// Display each card in the shuffled deck:
	auto suit = []( card c ) { return "SHDC"[c/13]; };
	auto rank = []( card c ) { return "AKQJT98765432"[c%13]; };
	for (card c : deck)
	{
		cout << ' ' << rank(c) << suit(c);
	}
    cout << endl;
}

