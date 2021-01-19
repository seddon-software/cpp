/*******************************************************************
 *
 * Roman Numerals
 *
 ******************************************************************/

#include <iostream>
#include <map>
#include <list>
#include <string>
#include <sstream>

using namespace std;

typedef map<int, string> DecimalToRomanMap;
typedef map<char, int> RomanToDecimalMap;

DecimalToRomanMap lookup = {
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
     {4000, "MMMM"}
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
    int digit4 = ((decimal/1000)%10)*1000;
    int digit3 = ((decimal/ 100)%10)* 100;
    int digit2 = ((decimal/  10)%10)*  10;
    int digit1 = ((decimal/   1)%10)*   1;

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

int main()
{
	for(int n = 1; n <= 4000; n++)
	{
		cout << n << ", " << decimalToRoman(n) << endl;
	}

	for(int n = 1; n <= 4000; n++)
	{
	    string r = decimalToRoman(n);
	    cout << romanToDecimal(r) << endl;
	}
}
