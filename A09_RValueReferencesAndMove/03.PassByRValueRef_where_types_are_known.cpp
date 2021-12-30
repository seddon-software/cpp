#include <iostream>
using namespace std;

/*  When passing by r-value reference, there is is a big difference between the case where 
 *  the references (l-value or r-value) are explicitly specified and the case where the 
 *  compiler deduces the types (as in a template or using auto).  
 * 
 *  In this example we provide overload functions separately for l-value and r-value references.
 *  This means the compiler does not need to deduce the reference types (no universal references 
 *  in this case).  Therefore long lived objects (l-value refs) will use the l-value ref overload
 *  and temporaries (r-value refs) will use the r-value ref overload.
 */


class X
{
public:
	X() {}
};

// f is overloaded for both l-value and r-value references
void f(X& x)
{
	cout << "l-value ref" << endl;
}

void f(X&& x)
{
	cout << "r-value ref" << endl;
}

void g(auto& x)
{
	cout << "l-value ref" << endl;
}

void g(auto&& x)
{
	cout << "r-value ref" << endl;
}

X h() // returns an r-value
{
	X x;
	return x;
}

int main()
{
	X x;
	f(x);		 	// argument is lvalue: calls f(X&)
	f(h());    		// argument is rvalue: calls f(X&&)
	f(X());       	// argument is rvalue: calls f(X&&)
	g(x);		 	// argument is lvalue: calls g(X&)
	g(h());    		// argument is rvalue: calls g(X&&)
	g(X());       	// argument is rvalue: calls g(X&&)
}
