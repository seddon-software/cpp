#include <iostream>
#include <type_traits>
using namespace std;

/*
 *  In this example we examine the difference between std::move<T> and std::forward<T>.
 *      std::move always returns an argument as an r-value reference
 *      std::forward returns either an l-value reference or an r-value reference dependent on how
 *        the argument was passed to the current function. 
 * 
 *  Note that there are 2 overloads of the show() function:
 *              void show(int&&)
 *              void show(int&)
 * 
 *  but only one overload of f()
 *              void f(T&& x)
 * 
 *  When there are l-value and r-value reference overloads, the compiler will call the appropriate overload,
 *  but when there is only a r-value reference version of a function, the compiler will allow both r-value and 
 *  l-value entities to be passed as parameters.  In this later case the compiler deduces the type (universal
 *  references).
 *  
 *  When you run this example notice that f() is called with r and l value references, but by using std::move
 *  the reference is always converted to an r-value reference and
 *              void show(int&&)
 *  is always called.
 * 
 *  Contrast that with what happens when you use std::forward.  If you pass an r-value reference to f() then
 *  forward also calls
 *              void show(int&&)
 * 
 *  but when you pass an l-value reference to f() forward calls
 *              void show(int&)
 * 
 *  Thus std::forward doesn't change the reference qualification and does perfect forwarding, but std::move
 *  always changes the reference qualification to r-value reference.
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
    cout << "show(int&&) called" << endl;
}
 
void show(int&)
{
    cout << "show(int&) called" << endl;
}

template<typename T> 
void f(T&& x)       // x can be either r or l value reference (universal reference)
{
    checkArg(std::move(x), "std::move(x)");
    show(std::move(x));
     
    checkArg(std::forward<T>(x), "std::forward(x)");
    show(std::forward<T>(x));
     
    cout << endl;
}
 
int main()
{
    f(100);     // call with r-value
 
    int x{100}; 
    f(x);       // call with l-value
}
