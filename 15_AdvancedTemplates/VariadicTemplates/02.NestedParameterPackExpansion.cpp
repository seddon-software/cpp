#include <iostream>
#include <string>
using namespace std;

/*
 *  Variadic template functions can call nested variadic template functions.
 *  Here we take the address of each parameter in f() and pass it onto g().
 */

template<class ...Us>
void g(Us... pArgs)
{
	cout << __PRETTY_FUNCTION__  << endl;
}

template<class ...Ts>
void f(Ts... args)
{
	cout << __PRETTY_FUNCTION__  << endl;
    g(&args...);    // “&args...” is a pack expansion
}


int main()
{
	string cyan("Cyan");
	f(100, 3.14159, "Red", cyan);
}
