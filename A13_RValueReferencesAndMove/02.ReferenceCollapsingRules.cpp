/*
 *  There is a second type of r-value reference, often called a Universal reference.  Universal references
 *  are only used in templates (or the equivalent auto declaration or in typedefs) when type deduction takes
 *  place.  Sometimes in templates a type is known, in which case, Universal references do not apply.
 * 
 *  Unfortunately, Universal references use the same notation as ordinary r value references, thereby causing
 *  confusion when you first encounter them.
 * 
 *  Universal references are always declared as:
 *              T&&
 * 
 *  but decay into both l value and r value references according to the reference collapsing rules.  In this 
 *  example we investigate these rules.  To help understand the rules you need to bear in mind that the standards
 *  commitee have defined the types of various artifacs as follows:
 *              a const (r value) is of type T
 *              a variable (l value) is of type T&
 *              a temporary (r value ref) is of type T&&
 *              a r value reference (l value) is of type T&
 * 
 */

#include<iostream>
#include<string>
using namespace std;

template <typename T>
void f(T&& t, const string& name)       // type deduction => universal reference
{
	if (std::is_lvalue_reference<T>::value)
		cout << name + "f(T&)" << endl;
	else
		cout << name + "f(T&&)" << endl;
}

struct X
{
    X(int i=0): i(i) {}
    ~X() { cout << "DTOR" << endl; }
    int i;
};

int main()
{
    // case 1: r value has type X
    f(10, "X => ");                 // f(X &&) => f(X&&)
    
    // case 2: l-value has type X&
    X x{1};                    
    f(x, "X& => ");                 // f(X& &&) => f(X&)
    
    // case 3: r value ref has type X&&
    f(X{100}, "X&& => ");           // f(X&& &&) => f(X&&)

    // case 4: l value ref has type X&
    X& xref = x;                
    f(xref, "X& => ");              // f(X& &&) => f(X&)
}
