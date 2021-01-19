/*
 * Write a function that rotates the values of 3 variables.  For example:
 *     x = 100
 *     y = 200
 *     z = 300
 *     Rotate( ... )
 *     // x is now 200
 *     // y is now 300
 *     // z is now 100
 */

#include <iostream>
#include <tuple>
using namespace std;


tuple<int, int, int> Rotate(int a, int b, int c)
{
	tuple<int, int, int> t(b, c, a);
	return t;
}

int main()
{
	int x = 100;
	int y = 200;
	int z = 300;

	tuple<int, int, int> t = Rotate(x, y, z);
	x = get<0>(t);
	y = get<1>(t);
	z = get<2>(t);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "z = " << z << endl;
}
