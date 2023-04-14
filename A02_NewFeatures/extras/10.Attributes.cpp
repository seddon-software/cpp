////////////////////////////////////////////////////////////
//
//      Narrowing
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	[[maybe_unused]] double d {42.0};   // no compiler warning
	int x = 5;
	switch(x)
	{
		case 1: cout << "case 1" << endl; break;
		case 2: cout << "case 2"; 
		[[fallthrough]]; // no warning on fallthrough
		case 3: cout << " and case 3" << endl; break;
		case 4: cout << "cases 3 and 4" << endl; break;
		case 5: cout << "case 5" << endl; break;
	}
	[[maybe_unused]] float h = {42.7};
}

