/*
 *  Functions can have default parameters.  The only restriction is that defaults must all be defined 
 *  from the right hand side of the function.  Furthermore, the defaults must be specified in the function 
 *  prototype and not in the function itself.  
 * 
 *  Note that the compiler allows you to omit parameter names in the prototype because the names are ignored.
 *  This is common practice.
 */

#include <iostream>
using namespace std;

// defaults should be declared in the prototype
void f(int, int = 99, int = 999);  // prototype doesn't need to specify 
                                   // variable names

void f(int a, int b, int c)
{
	cout << "a=" << a << ",b=" << b << ",c=" << c << endl;
}

int main()
{
    f(1, 2, 3);
    f(11, 12);      // defaulting c
    f(21);          // defaulting b and c
}

