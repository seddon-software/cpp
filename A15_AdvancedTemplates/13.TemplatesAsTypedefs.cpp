#include <iostream>
using namespace std;

/*
 *  A surprising use of templates is to create aliases for a family of existing types.  This is effectively
 *  a generic typedef.  In this example we define an alias for pointer types.
 */


// alias template
template<class T>
using ptr = T*;		// clearer than using a typedef
// the name 'ptr<T>' is now an alias for pointer to T

int main()
{
	int x = 100;
	string hello("Hello World");

	// these two declarations are equivalent
	int*     p1 = &x;
	ptr<int> p2 = &x;
	cout << *p1 << ", " << *p2 << endl;

	// so are these
	string*     ps1 = &hello;
	ptr<string> ps2 = &hello;
	cout << *ps1 << ", " << *ps2 << endl;
}
