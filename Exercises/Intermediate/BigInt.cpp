#include <fstream>
#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <iostream>
//#include <filesystem>
#include <algorithm>
#include <iterator>
#include <sstream>

#include <cstdarg>

using namespace std;

class BigInt
{
public:
	BigInt():length(0), pNumber(0) {}
	BigInt(const string& count ...): length(stoi(count))
    {
		va_list args;
		va_start(args, count);
		pNumber = new int[length];
		try
		{
			for(int i = 0; i < length; i++)
			{
				pNumber[i] = va_arg(args, int);
			}
		}
		catch(...)
		{
			cout << "end" << endl;
		}
	}
	BigInt(const BigInt& rhs)
	{
		pNumber = new int[rhs.length];
		for(int i = 0; i < rhs.length; i++)
		{
			pNumber[i] = rhs.pNumber[i];
		}
		length = rhs.length;
	}
	~BigInt()
	{
		delete[] pNumber;
	}
	int size() { return length; }
	friend ostream& operator<<(ostream& out, const BigInt& b);
	friend BigInt operator+(const BigInt& lhs, const BigInt& rhs);
	BigInt& operator=(const BigInt& rhs)
	{
		if(this == &rhs) return *this;
		delete[] pNumber;
		pNumber = new int[rhs.length];
		for(int i = 0; i < rhs.length; i++)
		{
			pNumber[i] = rhs.pNumber[i];
		}
		length = rhs.length;
		return *this;
	}
private:
	int length;
	int* pNumber;
};

BigInt operator+(const BigInt& lhs, const BigInt& rhs)
{
	BigInt result;

	int length = max(lhs.length, rhs.length) + 1;  // account for overflow
	int* pResult = new int[length]();		// zero out arrays
	int* pLHS = new int[length]();
	int* pRHS = new int[length]();

	for(int i = 0; i < lhs.length; i++)
	{
		pLHS[length+i-lhs.length] = lhs.pNumber[i];
	}
	for(int i = 0; i < rhs.length; i++)
	{
		pRHS[length+i-rhs.length] = rhs.pNumber[i];
	}
	for(int i = length-1; i >= 0; i--)
	{
		int sum = pLHS[i] + pRHS[i];
		sum += pResult[i];
		pResult[i] = sum % 1000;
		if(i >= 0) pResult[i-1] = sum / 1000;
	}

	int skip;
	if(pResult[0] == 0)  // check for leading zero
	{
		result.length = length - 1;
		skip = 1;
	}
	else
	{
		result.length = length;
		skip = 0;
	}

	result.pNumber = new int[result.length];

	for(int i = 0; i < result.length; i++)
	{
		result.pNumber[i] = pResult[i+skip];
	}

	return result;
}

ostream& operator<<(ostream& out, const BigInt& b)
{
	out << b.pNumber[0];
	for(int i = 1; i < b.length; i++)
	{
		out << setw(3) << setfill('0') << b.pNumber[i];
	}
	return out;
}

int main()
{
	BigInt b1("3",235,467,210);
	BigInt b2;
	BigInt b3(b1);
	cout << b1 << endl;
	b2 = b1;
	cout << b2 << endl;
	cout << b3 << endl;

	BigInt b4("4", 899,999,999,999);
	BigInt b5("2",         123,457);
	BigInt b6("4", 100,000,123,457);
	cout << b4 + b5 << endl;
	cout << b4 + b6 << endl;
}
