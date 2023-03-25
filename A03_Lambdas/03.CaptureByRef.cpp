#include <iostream>
using namespace std;

/*  
 *  If you want to work with updated values of variables you can use [&] to capture by reference.
 *  Note that the updated values of x and y are seen by the lambda when it is invoked.  Again, you
 *  don't have to capture everything, [&x, &y] only captures the named variables by reference. 
 *  You can mix captures; [&x, y] captures x by reference and y by value and you invoke the lambda
 *  immediately by hitting it with ().
 */ 

int main()
{
	int x = 10;
	int y = 5;

	// capture everything by reference
	auto add = [&](){ return x + y; };

    // change x and y before calling the lambda
	x = 100;
	y = 50;
	cout << add() << endl;

	// capture x and y by reference
	auto subtract = [&x, &y](){ return x - y; };
	cout << subtract() << endl;

    // capture x by reference and y by value and execute the lambda immediately.
	[&x, y](){ cout << "x=" << x << " y=" << y << endl;}();
}
