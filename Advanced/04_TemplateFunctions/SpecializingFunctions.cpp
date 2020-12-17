////////////////////////////////////////////////////////////
//
//		Specialising Template Functions
//
////////////////////////////////////////////////////////////

#include <string>
#include <cstring>
using namespace std;


template <typename T>
T Max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

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
	string s;
	 
	// const char*
	s = Max("Red", "Blue");
	s = Max("Blue", "Red");
	 
	// string
	s = Max<string>("Red", "Blue");			// explicit syntax
	s = Max(string("Blue"), string("Red"));	// coerce types

	return 0;
}

