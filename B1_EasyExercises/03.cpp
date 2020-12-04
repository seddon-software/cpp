/*
 * Write a program that prints out the square, cubes and fourth
 * power of the first 20 integers.
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	string format = "%6s";
	cout << setw(8) << "N"
		 << setw(8) << "N^2"
		 << setw(8) << "N^3"
		 << setw(8) << "N^4" << endl;

	for(int i = 1; i <= 20; i++)
	{
		cout << setw(8) << i
			 << setw(8) << i*i
			 << setw(8) << i*i*i
			 << setw(8) << i*i*i*i << endl;
	}
}

