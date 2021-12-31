#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

/* r-value references were introduced C++11 to solve a number of problems.  The most important of
 * these are:
 *
 *   Implementing move semantics (e.g. to efficiently copy temporaries)
 *   Perfect forwarding (reference types should not be altered when forwarding to another function) 
 *
 * r-value references indicate the item is a temporary and NOT a long lived object (l-value reference).
 * r-value refs use the new notation T&&.  However this is meant to be used in function parameter lists
 * where we give the temporary a name and effectively extend the lifetime of the temporary for the 
 * duration of the function.  It is possible to use r-value references outside of a function to declare
 * variables, but by doing so the variable, by definition, will not be temporary and the compiler will
 * internally note the variable is really an l-value reference.  Thus an r-value reference to a temporary
 * stays an rvalue reference, but rvalue references to named objects collapse into an l-value reference.
 * 
 * Some examples of the above are illustrated below:
 */

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
