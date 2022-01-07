#include <iostream>
#include <type_traits>
using namespace std;

/*
 *  In this example we examine the difference between std::move and std::forward<T>.
 *      std::move returns an argument as an r-value reference
 *      std::forward returns either an l-value reference or an r-value reference dependent on how
 *        the argument was passed in to the current function. 
 * 
 *  To illustrate the difference, we define a templated function f(T&& x) that takes a single parameter
 *  and subsequently calls the show() function (overloaded with l-value ref and r-value ref).  When 
 *  f(T&& x) is called std::move always converts x into an r-value ref.  However when f(T&& x) is called 
 *  with an r-value, std:forward passes an r-value reference to show(), but when called with an l-value
 *  std::forward passes an l-value reference to show().  Thus std::move always produces an r-value ref and
 *  std::forward always does perfect forwarding.
 */

template <typename T>
void checkArg(T&& parameter, const string& name)
{
	if (std::is_lvalue_reference<T&&>::value)
		cout << name + " is an l-value ref" << endl;
	else
		cout << name + " is an r-value ref" << endl;
}

void show(int&&)
{
    cout << "int&& called" << endl;
}
 
void show(int&)
{
    cout << "int& called" << endl;
}
 
template<typename T> 
void f(T&& x)
{
    checkArg(std::move(x), "std::move(x)");
    cout << "std::move(x): ";
    show(std::move(x));
     
    checkArg(std::forward<T>(x), "std::forward(x)");
    cout << "std::forward(x): ";
    show(std::forward<T>(x));
     
    cout << endl;
}
 
int main()
{
    f(100);     // call with r-value
 
    int x{100}; 
    f(x);       // call with l-value
}
