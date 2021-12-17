#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// An rvalue reference to an rvalue reference
//		becomes (“collapses into”) an rvalue reference.
// All other references to references (i.e., all combinations involving an lvalue reference)
//		collapse into an lvalue reference.

class X
{
public:
	X() {}
};

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
	auto&& r1 = x;	// looks like a r-value ref, but is it?
	auto&& r2 = cx;	// looks like a const r-value ref, but is it?

	checkArg(r, "r");
	checkArg(r1, "r1");
	checkArg(r2, "r2");
	checkArg(X(), "X()");
}
