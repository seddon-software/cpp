////////////////////////////////////////////////////////////
//
//      Default Parameters
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*
 *  Functions can have default parameters.  The only restrictions is that defaults must
 *  all be defined from the right side of the function.
 */

void f(int, int = 99, int = 999);  // prototype doesn't need to specify 
                                   // variable names

void f(int a, int b, int c)
{
	cout << a << "," << b << "," << c << endl;
}

int main()
{
    f(1, 2, 3);
    f(11, 12);
    f(21);
}

