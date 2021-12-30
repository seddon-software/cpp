#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

/* Rvalue references were introduced C++11 to solve a number of problems.  However, it is not immediately 
 * obvious what problems they solve.
 
1. Rvalue references can be used to extend the lifetimes of temporary objects (note, lvalue references to const can extend the lifetimes of temporary objects too, but they are not modifiable through them): 
2. More importantly, when a function has both rvalue reference and lvalue reference overloads, the rvalue reference overload binds to rvalues (including both prvalues and xvalues), while the lvalue reference overload binds to lvalues: 


Rvalue references solve at least two problems:

    Implementing move semantics
    Perfect forwarding 
*/

// An rvalue reference to a temporary becomes (“collapses into”) stays an rvalue reference.
// All rvalue references to named objects collapse into an lvalue reference.

struct X {};  // dummy class for testing

template <typename T>
void checkArg(T&& parameter, const string& name)
{
	if (std::is_lvalue_reference<T&&>::value)
		cout << name + " is an l-value ref" << endl;
	else
		cout << name + " is an r-value ref" << endl;
}

int main()
{
	X x;
	const X cx;
	auto& r = x;
	auto&& rr1 = x;			// looks like a r-value ref, but is it?
	auto&& rr2 = cx;		// looks like a r-value ref, but is it?

	checkArg(r, "r");		// l-value ref
	checkArg(rr1, "rr1");	// has a name, so l-value ref
	checkArg(rr2, "rr2");	// has a name, so l-value ref
	checkArg(X(), "X()");	// X() creates a temporary, so it is an r-value-ref
}
