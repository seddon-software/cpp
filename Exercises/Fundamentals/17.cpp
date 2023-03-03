/*
 * Write a program that calculates the factorial of an integer
 * in the range 2 to 10.  Add exception handling code to prevent
 * calculating a result where the input number is larger than 10,
 * or any negative integer.
 */

#include <iostream>
#include <stdexcept>
using namespace std;

int factorial(int n)
{
	if(n == 1) return 1;
	return n * factorial(n - 1);
}

int main()
{
	try {
		cout << "Enter an integer (2-10): " << endl;
		string input;
		getline(cin, input);
		int x = stoi(input);
		if(x < 2) throw out_of_range("value too small");
		if(x > 10) throw out_of_range("value too large");

		cout << "factorial(" << x << ") = " << factorial(x) << endl;

	} catch(const out_of_range& e) {
		cerr << e.what() << endl;
	}
}
