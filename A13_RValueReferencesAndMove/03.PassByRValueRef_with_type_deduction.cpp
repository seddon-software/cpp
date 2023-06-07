#include <iostream>
#include <type_traits>
using namespace std;

/*  When passing by r-value reference, there is is a big difference between the case where 
 *  references (l-value or r-value) are explicitly specified in a function parameter list
 *  and the case where the compiler deduces the reference type (as in a template or using auto).  
 * 
 *  When a templated function specifies a parameter as an r-value reference and does not provide
 *  an l-value ref overload, this does not imply the parameter passed is an r-value reference.
 *  This is counter intuitive, but the collapsing rules shown earlier mean the actual parameter
 *  passed can be either an l-value ref or r-value ref and the compiler has to deduce which is 
 *  which.  This use of an r-value reference is often called a universal reference because it 
 *  can go either way. 
 *  
 *  This example focuses on these universal references (note there are no explicit l-value 
 *  ref overloads).
 */

class X
{
public:
	X() {}
    ~X() { cout << "DTOR" << endl; }
	void hello()
	{
		cout << "Hello from temporary X object" << endl;
	}
	static X& make()
	{
		return *new X{};
	}
};

// f is only overloaded for r-value references
// T&& does NOT imply an r-value reference is actually passed.  The parameter passed can 
// be either a reference to a long lived object (l-value) or a reference to a temporary (r-value)
template <typename T>
void f(T&& t)		
{
	if (std::is_lvalue_reference<T&&>::value)  // l-value
		cout << "t is an l-value ref" << endl;
	else  // the temporary is still alive
	{
		cout << "t is an r-value ref" << endl;
		t.hello();
	}
}

// alternatively we can use auto&& (equivalent to the template above)
void g(auto&& t)
{
	if (std::is_lvalue_reference<decltype(t)>::value)
		cout << "t is an l-value ref" << endl;
	else  // the temporary is still alive
	{
		cout << "t is an r-value ref" << endl;
		t.hello();
	}
}

X h()
{
	X x;
	return x;
}

int main()
{
	X x;
	f(x);	  // argument is lvalue
	f(X());   // argument is rvalue (temporary)
	f(h());   // argument is rvalue (return value not saved and thus temporary)
	g(x);	  // argument is lvalue
	g(X());   // argument is rvalue (temporary)
	g(h());   // argument is rvalue (return value not saved and thus temporary)
}
