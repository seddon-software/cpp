#include <iostream>
using namespace std;

// When passing by r-value reference, there is is a BIG difference
// between the case where the types are explicitly specified and
// the case where the compiler deduces the types.
// This example focusses on the former.

class X
{
public:
	X() {}
};

// foo is overloaded for l-value and r-value references
void foo(X& x)
{
	cout << "X&" << endl;
}

void foo(X&& x)
{
	cout << "X&&" << endl;
}

X foobar() // returns an r-value
{
	X x;
	return x;
}

int main()
{
	X x;
	foo(x);		 	// argument is lvalue: calls foo(X&)
	foo(foobar());  // argument is rvalue: calls foo(X&&)
	foo(X());
}
