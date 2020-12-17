/*
 * Write a program that prints out the sum, difference, product
 * and dividend of two complex numbers.
 */

#include <iostream>
#include <complex>
using namespace std;

int main()
{
	complex<double> x(5,  3); 		// x = 5 + 3j
	complex<double> y(4, -2); 		// y = 4 - 2j

	cout << "sum = "        << x + y << endl;
    cout << "difference = " << x - y << endl;
    cout << "product = "    << x * y << endl;
    cout << "dividend = "   << x / y << endl;
}


