#include <iostream>
using namespace std;

/* 
 *  Functions can now use a trailing return type syntax.  This was introduced to allow a function to
 *  compute its return type based on its input types.  You can also use this notation where thereurn 
 *  type is known.  Note that you must specify the return type as auto, the compiler will do the rest.
 * 
 *  In the case of declspec, the compiler does not evaluate the expression, but does compute the type
 *  yielded by the expression.  Note that C++14 compilers will compute the return type without using
 *  the trailing return type syntax provide the function is fully defined before it is first used (a
 *  function prototype is not sufficient).
 */

// function prototypes
auto f(int a, int b) -> int;
auto g(auto a, auto b) -> decltype(a + b);
// auto h(int a, int b);  this doesn't compile (can't deduce auto)

// from C++14 the compiler can automatically detect return type (must be defined before the call)
auto h(int a, int b)
{
	return a + b;
}

int main()
{
	cout << f(5, 10) << endl;
	cout << g(20, 25) << endl;
	cout << g(35, 40.3) << endl;
	cout << h(35, 40) << endl;
}

auto f(int a, int b) -> int    // function returns an int
{
	return a + b;
}

// the auto parameters get converted to template args
auto g(auto a, auto b) -> decltype(a + b)  // the function returns the type of a + b
{
	return a + b;
}

