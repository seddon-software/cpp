#include <iostream>


/*
 *  This example shows how to use references.
 *  References are aliases.
 */


// using namespace tells the compiler which namespaces to seach.  The std:: is then unnecessary.
using namespace std;

int main()
{
	int x = 100;
	int* p = &x;

	int& xx = x;			// xx is an alias for x
	int& xxx = xx;			// xxx is an alias for x and xxx

	int*& pp = p;			// pp is an alias for p
	int*& ppp = p;			// ppp is an alias for p and pp

	// all these lines are equivalent
	cout << x << endl;
	cout << xx << endl;
	cout << xxx << endl;
	cout << *p << endl;
	cout << *pp << endl;
	cout << *ppp << endl;
}
