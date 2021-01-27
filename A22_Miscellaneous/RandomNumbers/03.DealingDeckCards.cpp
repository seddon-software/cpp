#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <clocale>

std::default_random_engine & global_urng()
{
	static std::default_random_engine u{};
	return u;
}

void randomize()
{
	static std::random_device rd{};
	global_urng().seed(rd());
}

int main()
{
// setup engine
	static std::random_device rdev{};
	static std::default_random_engine engine{rdev()};

// Manufacture a deck of cards:
	using card = int;
	std::array<card, 52> deck{};
	std::iota(deck.begin(), deck.end(), 0);

// Shuffle the deck:
	std::shuffle(deck.begin(), deck.end(), engine);

// Display each card in the shuffled deck:
	auto suit = []( card c ) { return "SHDC"[c/13]; };
	auto rank = []( card c ) { return "AKQJT98765432"[c%13]; };
	for (card c : deck)
	{
		std::cout << ' ' << rank(c) << suit(c);
	}
}

