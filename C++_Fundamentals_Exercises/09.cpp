/*
 * Write a function to convert a string representing a binary number to an int.
 * Use this function to compute the decimal value of the binary
 * number 101010101010101010101
 */

#include <iostream>
#include <list>
using namespace std;

int convert(const string& text)
{
	int result = 0;

    for(int i = 0; i < text.size(); i++)
    {
    	result *= 2;
    	int k = text[i] - '0';
    	result += k;
    }
    return result;
}

int main()
{
	string binaryNumber = "101010101010101010101";
	int decimalNumber = convert(binaryNumber);
    cout << decimalNumber << endl;
}

