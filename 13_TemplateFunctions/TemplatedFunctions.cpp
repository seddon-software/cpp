////////////////////////////////////////////////////////////
//
//		Template Functions
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


template <typename T>
T Max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}


/////

int main()
{
	string s1 = "Red";
	string s2 = "Blue";
	cout << Max(5, 8) << endl; 			// calls template with T = int
	cout << Max(5.1, 8.3) << endl; 		// calls template with T = double
	cout << Max(s1, s2) << endl; 		// calls template with T = string
	// double x = Max(5.1, 8);			// ambiguous
	 
	return 0;
}

