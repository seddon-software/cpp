////////////////////////////////////////////////////////////
//
//		Special Cases
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstring>
#include <type_traits>
using namespace std;

/*
 *  The problem with const char* parameters can be overcome in a number of ways.  Perhaps the simplest
 *  is to provide a specialized function for the type.  If the compiler has a choice between using a
 *  template or a function, it will always prefer the function.
 */

template <typename T>
T Max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

// this function is called in preference to the template
const char* Max(const char* a, const char* b)
{
	if (strcmp(a,b) > 0)
		return a;
	else
		return b;    
}

/////

int main()
{
	// these lines now compare the contents of the const char* and hence give the correct result
	cout << Max("Red", "Blue") << endl;
	cout << Max("Blue", "Red") << endl;

	// the string type will use the template
	string s1("Red");
	string s2("Blue");	 
	cout << Max(s1, s2) << endl;
	cout << Max(s2, s1) << endl;
}

