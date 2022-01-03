#include <iostream>
using namespace std;

/*  
 *  A lambda can capture state from enclosing scope using the [] clause.  In this example we use [=] 
 *  to capture the entire enclosing scope (a closure), namely the variables x and y.  The capure is
 *  by default capture by value, which means the x and y inside the lambda are copies of x and y and 
 *  hence subsequent changes to x and y don't affect the lambda.  
 * 
 *  Of course you don't have to capture everything from enclosing scope. [x, y] only captures the 
 *  named variables.
 */

int main()
{
	int x = 10;
	int y = 5;

	// capture everything by value
	auto add = [=](){ return x + y; };

    // change x and y before calling the lambda
	x = 100;
	y = 50;
	cout << add() << endl;

	// capture x and y by value
	auto subtract = [x, y](){ return x - y; };

	cout << subtract() << endl;
}
