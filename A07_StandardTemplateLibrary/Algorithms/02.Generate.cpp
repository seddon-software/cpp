#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


int main()
{
	// generate a vector of integers in range 0..49
	vector<int> v(50);

	// the implicit operator() of a lambda is const. 
	// => start is const int
	// mark lambda as mutable to make operator() non-const and hence start as non-const:
	generate(v.begin(), v.end(), [start = 0]() mutable { return start++; });

	// use a for loop to print the vector
	for(auto i:v) cout << i << ", "; 
	    cout << endl;
	// use copy to print the vector
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}

