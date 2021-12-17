#include <vector>
#include <iostream>
using namespace std;

/*
 *  Although the STL Containers do not accept reference types as template parameters
 *  in general templates can accept reference types.  The STL Containers are designed
 *  as "value" containers and as such do not accept items by reference, but other templates
 *  are perfectly happy with reference types.
 *
 */

struct A
{
	int x;
};

template <class T>
void f(T t)
{
	// modify a copy of t if T is not a reference type
	// modify t if T is a reference type
	t.x = 77;
}

int main()
{
	A v;
	v.x = 100;

	f<A>(v);			// pass v by value
	cout << v.x << endl;

	f<A&>(v);			// pass v by reference
	cout << v.x << endl;
}
