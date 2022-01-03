#include <iostream>
using namespace std;

/*  lambdas were introduced with C++11 and define anonymous function objects.  Typically these function
 *  objects are assigned to a variable, as with "add" below.  A lambda has 3 parts:
 *		[]		for captures
 *		()		for parameters
 *		{}		for the body of the function object
 *
 *  lambdas are called in the same way as normal functions.  However the [] captures allow the function 
 *  objects to have state (see later), making them functors.  In fact lambda are basically syntax suger
 *  for functors.
 */

int main()
{
	auto add = [](int x, int y){ return x + y; };  // define the function object

	cout << add(5, 10) << endl;  // call it
}
