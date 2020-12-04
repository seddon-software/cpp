#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// note: boost::lexical_cast doesn't work with -std=c++11 in gcc 4.7

using namespace std;

unordered_map<string, int> roman_to_modern =
{
	{"I", 1},
	{"V", 5},
	{"X", 10},
	{"L", 50},
	{"C", 100},
	{"D", 500},
	{"M", 1000},
};

unordered_map<int, string> modern_to_roman =
{
	{0, ""},
	{1, "I"},
	{2, "II"},
	{3, "III"},
	{4, "IV"},
	{5, "V"},
	{6, "VI"},
	{7, "VII"},
	{8, "VIII"},
	{9, "IX"},
	{10, "X"},
	{20, "XX"},
	{30, "XXX"},
	{40, "XL"},
	{50, "L"},
	{60, "LX"},
	{70, "LXX"},
	{80, "LXXX"},
	{90, "XC"},
	{100, "C"},
	{200, "CC"},
	{300, "CCC"},
	{400, "CD"},
	{500, "D"},
	{600, "DC"},
	{700, "DCC"},
	{800, "DCCC"},
	{900, "CM"},
	{1000, "M"},
	{2000, "MM"},
	{3000, "MMM"},
	{4000, "MMMM"},
};

class ConvertToModern
{
public:
	ConvertToModern() : prev(0) {}

	const int operator()(int& year, const char& next)
	{
		stringstream ss;
		ss << next;

		int n = roman_to_modern[ss.str()];
		if(n < prev)
			year -= n;
		else
			year += n;
		prev = n;
		return year;
	}
private:
	int prev;
};

class ConvertToRoman
{
public:
	string operator()(string& year, const int& n)
	{
		year += modern_to_roman[n];
		return year;
	}
};


int toModern(string roman)
{
	reverse(roman.begin(), roman.end());
	return accumulate(roman.begin(), roman.end(), 0, ConvertToModern());
}

string toRoman(int modern)
{
	stringstream ss;
	ss << setw(4) << modern;
	string s = ss.str();

	vector<int> v =
	{
		(int)(s[0] - '0') * 1000,
		(int)(s[1] - '0') * 100,
		(int)(s[2] - '0') * 10,
		(int)(s[3] - '0') * 1,
	};
	return accumulate(v.begin(), v.end(), string(""), ConvertToRoman());
}

int main()
{
	cout << toModern("MCMXXXIV") << endl;
	cout << toRoman(1934) << endl;

	for(int year = 1; year < 4000; year++)
	{
		int derivedYear = toModern(toRoman(year));
		if(derivedYear != year) cout << year << ": test failed" << endl;
	}
}

