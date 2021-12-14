#include <iostream>

/*
 *  This example shows how to use references.
 *  References are aliases.
 */


// using namespace tells the compiler which namespaces to seach.  
// The std:: is then not required.  You should know that the use
// of this construct is not universally accepted.  There are lots of discussions
// on the web about thepros and cons of the following line: 
using namespace std;

int main()
{
    int x = 100;
    int* p = &x;            // p is a pointer to an int

    int& xx = x;			// xx is an alias for x
    int& xxx = xx;			// xxx is an alias for x and xx

    int*& pp = p;			// pp is an alias for p
    int*& ppp = p;			// ppp is an alias for p and pp

    // all these lines are equivalent and print out the value of x (100):
    cout << x << endl;
    cout << xx << endl;
    cout << xxx << endl;
    cout << *p << endl;
    cout << *pp << endl;
    cout << *ppp << endl;
}
