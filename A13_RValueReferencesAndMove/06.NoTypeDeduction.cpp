#include <iostream>
using namespace std;

/*  Here we concentrate on the case where we are not using universal references.  
 * 
 *  In this example we provide separate overloaded functions for l-value and r-value references.
 *  This means the compiler does not need to deduce the reference types (no universal references 
 *  in this case).  Therefore long lived objects (l-value refs) will use the l-value ref overload
 *  and temporaries (r-value refs) will use the r-value ref overload.
 * 
 *  Note that h is essentially the same as g.  Although g is a template the compiler does not need to 
 *  deduce the type (r-value or l-value) as both overloads are provided. 
 */


class X
{
public:
	X() {}
    ~X() { cout << "DTOR" << endl; }
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

// g is overloaded for both l-value and r-value references
template <typename T>
void g(T& x)
{
	cout << "l-value ref" << endl;
}

template <typename T>
void g(T&& x)
{
	cout << "r-value ref" << endl;
}

void h(auto& x)
{
	cout << "l-value ref" << endl;
}

void h(auto&& x)
{
	cout << "r-value ref" << endl;
}

X fn() // returns a temporary
{
	X x;
	return x;
}

int main()
{
	X x;
	f(x);		 	// argument is lvalue: calls f(X&)
	f(fn());    	// argument is rvalue: calls f(X&&)
	f(X());       	// argument is rvalue: calls f(X&&)

	g(x);		 	// argument is lvalue: calls g(X&)
	g(fn());    	// argument is rvalue: calls g(X&&)
	g(X());       	// argument is rvalue: calls g(X&&)

	h(x);		 	// argument is lvalue: calls g(X&)
	h(fn());    	// argument is rvalue: calls g(X&&)
	h(X());       	// argument is rvalue: calls g(X&&)
}
