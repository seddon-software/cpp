/*
 * Write a program that prints out the first 20 Fibonacci
 * numbers.  You can use the web to find out the definition
 * of the Fibonacci sequence.
 */

#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 1;

	for(int i = 1; i <= 20; i++)
	{
		cout << a << ",";
		int old_a = a;
		a = b;
		b = old_a + b;
	}
	cout << endl;
}
    
