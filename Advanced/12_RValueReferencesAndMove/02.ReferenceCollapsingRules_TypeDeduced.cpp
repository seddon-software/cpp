#include <iostream>
#include <type_traits>
using namespace std;

// When passing by r-value reference, there is is a difference
// between the case where the types are explicitly specified and
// the case where the compiler deduces the types (as in a template or using auto).
// This example focusses on the latter.

class X
{
public:
	X() {}
	static X& make()
	{
		return *new X();
	}
};

// foo is only overloaded for r-value references
// but T&& does NOT imply r-value reference (when type deduction is involved)
//	T&& can be either a r-value or l-value in this case
template <typename T>
void foo(T&& t)		// universal ref
{
	if (std::is_lvalue_reference<T&&>::value)
		cout << "t is an l-value ref" << endl;
	else
		cout << "t is an r-value ref" << endl;
}

int main()
{
	X x;
	foo(x);	  // argument is lvalue
	foo(X()); // argument is rvalue
}
