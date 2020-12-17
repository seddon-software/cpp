////////////////////////////////////////////////////////////
//
//		Arrays
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdio>
#include <boost/array.hpp>
using namespace std;
#define cout cout << " "

int main()
{
	boost::array<int,4> a = { { 1, 2, 3 } };		// last entry flled with zero
	boost::array<int,4> b = { { 2, 4, 6, 8 } };

	boost::array<int,4> result;

	for(unsigned i = 0; i < a.size(); i++)
	{
		result[i] = a[i] + b[i];
	}

	for(unsigned i = 0; i < a.size(); i++)
	{
		cout << result[i] << endl;
	}

    return 0;
}
