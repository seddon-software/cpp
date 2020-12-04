#include <iostream>
#include <string>
using namespace std;

/*
 *  Variadic templates employ parameter packs.
 *  ...Ts denotes a parameter pack
 *  Ts... expands the pack
 *  __PRETTY_FUNCTION__ is a gcc extension
 */

template<class ...Ts>
void f(Ts... args)
{
	cout << __PRETTY_FUNCTION__  << endl;
}


int main()
{
	string cyan("Cyan");
	f(100, 3.14159, "Red", cyan);
}
