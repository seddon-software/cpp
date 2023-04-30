#include <iostream>

/*
 *  This example shows how to use references.  References can be thought of as aliases for existing 
 *  variables.  Once a referenc e is set, it cannot be changed.  For example:
 *              int& xx = x;
 *  sets up xx as an alias for x.  That means xx is an alternative name for x.  The compiler does not
 *  allocate storage for xx because xx is really x.  Note that the & in C means "address of", but here
 *  & declares a reference.  The spacing is not important to the compiler; equally we could have written:
 *              int &xx = x or even
 *              int & xx = x
 *  Note that:
 *              xx = y;
 *  despite appearances, is identical to:
 *              x = y;
 *  and does not reassign the reference xx.  Recall that once a reference is set it can't be changed.
 *  
 *  We can also define references (aliases) for pointers.  In this case the reference is referring to an
 *  int*, so we write:
 *              int*& pp = p;
 *  and now pp is an alias for p.
 */


// using namespace tells the compiler which namespaces to seach.  
// The std:: is then not required.  You should know that the use
// of this construct is not universally accepted.  There are lots of discussions
// on the web about the pros and cons of the following line: 
using namespace std;

int main()
{
    int x = 100;
    int* p = &x;            // p is a pointer to an int

    int& xx = x;			// xx is an alias for x
    int& xxx = xx;			// xxx is an alias for x and xx

    int y = 200;
    xx = y;                 // same as x = y
    cout << x << endl;

    int*& pp = p;			// pp is an alias for p
    int*& ppp = p;			// ppp is an alias for p and pp

    // all these lines are equivalent and print out the value of x (100):
    cout << x << endl;
    cout << xx << endl;
    cout << xxx << endl;
    cout << *p << endl;
    cout << *pp << endl;
    cout << *ppp << endl;

    // note x, xx and xxx all refer to the same storage address
    cout << &x << endl;
    cout << &xx << endl;
    cout << &xxx << endl;
    cout << p << endl;
    cout << pp << endl;
    cout << ppp << endl;
}
