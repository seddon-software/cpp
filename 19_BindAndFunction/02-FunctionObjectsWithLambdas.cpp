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

// This example effectively allows defining nested functions in C++

int main()
{
	int n = 0;

	// create pointer to function objects using closure on reference to n;
	std::function<int(int,int)> f =
		[&n](int x, int y)
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

