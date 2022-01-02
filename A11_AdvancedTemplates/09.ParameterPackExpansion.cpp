#include <iostream>
#include <string>
using namespace std;

/*  Variadic templates were introduced in C++11 to allow templates to have a variable number of 
 *  parameters.

 *  Variadic templates employ parameter packs.
 *  ...Ts denotes a parameter pack in the template clause and
 *  Ts... expands the pack in the body of the template
 *
 *  We use the __PRETTY_FUNCTION__ gcc extension to see what the expansion looks like in this
 *  simple example. 
 */

template<class ...Ts>
void f(Ts... args)
{
	cout << "function called as: void f(Ts... args) which expands to:" << endl;
	cout << __PRETTY_FUNCTION__  << endl;
	cout << endl;
}

int main()
{
    cout << "call f(100, 3.14159, \"Red\", string(\"Cyan\"))" << endl;
	f(100, 3.14159, "Red", string("Cyan"));
}
