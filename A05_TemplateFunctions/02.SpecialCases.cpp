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


template <typename T>
auto Max(T a, T b) -> decltype(a + b)
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
	cout << boolalpha;
	string s1("Red");
	string s2("Blue");
	 
	// const char*
	auto c = Max("Red", "Blue");
    if(is_same<decltype(c), const char*>::value)
	    cout << "return is const char*" << endl;

	// string
	auto s = Max(s1, s2);
    if(is_same<decltype(s), string>::value)
	    cout << "return is string" << endl;
}

