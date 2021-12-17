////////////////////////////////////////////////////////////
//
//		Template Functions
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

// note with T=const char* this template will compare pointers
template <typename T>
T Max(T a, T b)
{
//		std::cout << type_name<decltype(a)>() << '\n';
	if (a > b)
		return a;
	else
		return b;
}


/////

int main()
{
	cout << Max(5, 8) << endl;
	cout << Max(5.1, 8.3) << endl;
	// swap the next two lines to get a different result
	cout << Max("Red", "Blue") << endl;	// T = const char*
	cout << Max("Blue", "Red") << endl;
}

