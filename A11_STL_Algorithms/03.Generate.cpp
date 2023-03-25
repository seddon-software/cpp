#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/*
 * 	Generate a vector of integers in range 0..49.  The algorithm takes a range and a function pointer
 *  (we are using a lambda).  The underlying (compiler generated) lambda's operator() needs to modify 
 *  the "start" variable, captured and initialized by the lambda.  The operator() method is const by
 *  default, so we need to use mutable to make it non-const  
 */

int main()
{
	vector<int> v(50);

	// mark lambda body as mutable to make operator() non-const
    generate(v.begin(), v.end(), [start = 0]() mutable { return start++; });

	// use copy to print the vector
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

