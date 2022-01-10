////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <functional>
using namespace std;

//////

/*
 *  A number of authors have suggested that rather than use the bindings library, it is often cleaner
 *  to use lambda expressions.  Note that with lambdas, you have the added flexability of providing 
 *  closures.
 */

int main()
{
	int n = 0;

	// create pointer to function objects using closure on reference to n;
	std::function<int(int,int)> f;
    
    f =	[&n](int x, int y)   // closure on n
	    {
		    n++;
		    return x + y + n;
	    };

	// invoke
	n = 100;
	cout << f(10, 20) << endl;
	n = 200;
	cout << f(30, 40) << endl;
}

