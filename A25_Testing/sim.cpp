#include "sim.h"

HAND north;
HAND east;
HAND south;
HAND west;

tuple<HAND, HAND, HAND, HAND> deal()
{
// setup engine
	static std::random_device rdev{};
	static std::default_random_engine engine{rdev()};

// Manufacture a deck of cards:
	std::array<Card, 52> deck{};
	std::iota(deck.begin(), deck.end(), 0);

// Shuffle the deck:
	std::shuffle(deck.begin(), deck.end(), engine);

// Assign cards
	std::copy(&deck[ 0], &deck[13], &north[0]);
	std::copy(&deck[13], &deck[26], &east[0]);
	std::copy(&deck[26], &deck[39], &south[0]);
	std::copy(&deck[39], &deck[52], &west[0]);

	return std::make_tuple(north, east, south, west);
}

char convert(int pip)
{
	const char pips[] = "23456789TJQKA";
	char c = pips[pip%13];
	return c;
}
void printSuit(char suit, vector<char> v)
{
    cout << suit << ": ";
	for(char c : v) cout << c << " ";
	cout << endl;
}

void print(HAND& hand)
{
	std::sort(hand.begin(), hand.end(), greater<int>());
	vector<char> spades, hearts, diamonds, clubs;
	for (int n : hand) {
		if     (n < 13) clubs.push_back(convert(n));
		else if(n < 26) diamonds.push_back(convert(n));
		else if(n < 39) hearts.push_back(convert(n));
		else            spades.push_back(convert(n));
	}
	printSuit('s', spades);
	printSuit('h', hearts);
	printSuit('d', diamonds);
	printSuit('c', clubs);
}

void playHand(HAND hands[])
{
	for(int round = 0; round < 13; round++)
	{
		for(int player = 0; player < 4; player++)
		{
			cout << hands[player][round] << ",";
		}
		cout << endl;
		cout.flush();
	}
}

int main()
{
    tuple<HAND, HAND, HAND, HAND> hands = deal();
    north = get<0>(hands);
    east = get<1>(hands);
    south = get<2>(hands);
    west = get<3>(hands);
	print(west);
	HAND allHands[] = {north, east, south, west};
	playHand(allHands);
}