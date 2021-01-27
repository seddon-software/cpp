#include <algorithm>
#include <array>
#include <string>
#include <iostream>
#include <random>

using Card = int;
using namespace std;

int main()
{
// setup engine
	static std::random_device rdev{};
	static std::default_random_engine engine{rdev()};

// Manufacture a deck of cards:
	std::array<Card, 52> deck{};
	std::iota(deck.begin(), deck.end(), 0);

// Shuffle the deck:
	std::shuffle(deck.begin(), deck.end(), engine);
	std::shuffle(deck.begin(), deck.end(), engine);

// Display each card in the shuffled deck:
	auto suit = []( Card c ) { return "shdc"[c/13]; };
	auto rank = []( Card c ) { return "AKQJX98765432"[c%13]; };

// Assign cards
	std::array<Card, 13> north, east, south, west;
	std::copy(&deck[ 0], &deck[13], &north[0]);
	std::copy(&deck[13], &deck[26], &east[0]);
	std::copy(&deck[26], &deck[39], &south[0]);
	std::copy(&deck[39], &deck[52], &west[0]);

// print details
	auto printHand =
		[&](const string& player, auto hand)
		{
			auto calculatePoints =
				[&]()->int
				{
					int pts = 0;
					for(Card card : hand)
					{
						card = 4 - card % 13;
						if(card > 0) pts += card;
					}
					return pts;
				};

			cout << player << ": ";

			std::sort(hand.begin(), hand.end());
			for (Card c : hand)
			{
				cout << ' ' << rank(c) << suit(c);
			}
			cout << " >> " << calculatePoints();
			cout << endl;
		};

	printHand("NORTH", north);
	printHand("EAST ", east);
	printHand("SOUTH", south);
	printHand("WEST ", west);
}

