/*******************************************************************
 *
 * Roman Numerals
 *
 ******************************************************************/

#include <iostream>
#include <stdexcept>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>          // for accumulate

using namespace std;

typedef map<int, string> DecimalToRomanMap;
typedef map<char, int> RomanToDecimalMap;

DecimalToRomanMap lookup = {
        {0, ""},
        {1, "A"},
        {2, "AA"},
        {3, "AAA"},
        {4, "AB"},
        {5, "B"},
        {6, "BA"},
        {7, "BAA"},
        {8, "BAAA"},
        {9, "AC"},
};

RomanToDecimalMap symbols = {
		{'M',1000},
		{'D',500},
		{'C',100},
		{'L',50},
		{'X',10},
		{'V',5},
		{'I',1}
};

string decimalToRoman(int decimal)
{
//    decimalToRoman(2873);

    int digit4 = ((decimal/1000)%10)*1000;
    int digit3 = ((decimal/ 100)%10)* 100;
    int digit2 = ((decimal/  10)%10)*  10;
    int digit1 = ((decimal/   1)%10)*   1;
    x = lookup[digit4];
    
    return lookup[digit4] + lookup[digit3] + lookup[digit2] + lookup[digit1];
}

int romanToDecimal(const string& roman)
{
	/*
    if a roman symbol is less than its successor then it is negative
    */
	int decimal = 0;
    int previous = 0;

    for (auto it = roman.crbegin() ; it != roman.crend(); ++it) {
            int n = symbols[*it];
            if (n >= previous)
            	decimal += n;
            else
            	decimal -= n;
            previous = n;
    }
	return decimal;
}

int romanToDecimal2(const string& roman)
{
	/*
    if a roman symbol is less than its successor then it is negative
    */
    vector<int> v;
    for(auto c : roman)
    {
        v.push_back(symbols[c]);
    }

    for(size_t i = 1; i < v.size(); i++)
    {
        if(v[i] > v[i-1]) v[i-1] = -v[i-1];  // invert sign
    }
    return accumulate(v.begin(), v.end(), 0);
}

int main()
{
    decimalToRoman(2873);
	for(int n = 1; n <= 4000; n++)
	{
		cout << n << ", " << decimalToRoman(n) << endl;
	}

	for(int n = 1; n <= 4000; n++)
	{
	    string r = decimalToRoman(n);
	    cout << romanToDecimal2(r) << endl;
        if(romanToDecimal2(r) != n) throw runtime_error("conversion failed with year = "s + to_string(n));
	}
}
