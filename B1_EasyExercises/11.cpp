/*
 * Write a function that calculates the area of a rectangle.
 * Decide how many input parameters your function needs.
 * The area should be returned from the function.  Write a
 * test program that calls your function with different sets
 * of test data.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int Area(int length, int breadth)
{
    return length * breadth;
}

int main()
{
	// Tests
	cout << Area(40, 20) << endl;
	cout << Area(41, 19) << endl;
	cout << Area(42, 18) << endl;
	cout << Area(43, 17) << endl;
	cout << Area(44, 16) << endl;
}
