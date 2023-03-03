/*
 * Write a program that calculates the ratio of successive
 * pairs of the first 20 Fibonacci numbers.  Does the ratio
 * appear to converge to a special number?
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a = 0;
	int b = 1;

	for(int i = 1; i <= 20; i++)
	{
		int old_a = a;
		a = b;
		b = old_a + b;
		cout << b / double(a) << endl;
	}
	cout << endl;
	double phi = (1.0 + sqrt(5.0))/2.0;
	cout << "phi (golden ratio) = " << phi << endl;
}
    
