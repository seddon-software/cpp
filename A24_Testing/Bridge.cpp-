#include "Header.h"

using namespace std;

HAND north;
HAND east;
HAND south;
HAND west;


void Register(const string& message, FN fn, vector<int> range1, vector<int> range2)
{
    // register a function for each item in range
    FN0 fnx;
    for(auto& r1: range1)
    {
        for(auto& r2: range2)
        {
            ostringstream stream;
            stream << message << "(" << r1 << "," << r2 << ")";
            const string& x_message = stream.str();
            fnx = std::bind(fn, r1, r2);
            T item(x_message, 0, fnx);
            v.push_back(item);
        }
    }
}

vector<int> range(int lo, int hi)
{
    std::vector<int> range(hi - lo);
    std::iota(range.begin(), range.end(), lo);
    return range;
}

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

int suitLength(const HAND& hand, char suit)
{
	auto suitOf = []( Card c ) { return "shdc"[c/13]; };

	int count = 0;
	for(Card card : hand)
	{
		if(suitOf(card) == suit) count++;
	}
	return count;
}

int points(const HAND& hand)
{
    int pts = 0;
    for(Card card : hand)
    {
        card = 4 - card % 13;
        if(card > 0) pts += card;
    }
    return pts;
}

void progress(int i)
{
    if(i % (M/100) == 0) cout << (100*i)/M << "%, ";
    cout.flush(); 
    if(i == M - 1) cout << "100%" << endl;
}

