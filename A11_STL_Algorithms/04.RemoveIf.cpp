#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/*
 *  remove_if takes a range and a function pointer (we are using a lambda).  The lambda
 *  returns a boolean.  The example filters out all the odd numbers from the vector.
 */

int main()
{
	vector v{10,11,12,13,14,15,16,17,18,19,20};
	// filter out the odd numbers
	auto new_end = remove_if(v.begin(), v.end(), [](int n){ return n % 2 != 0; });
	copy(v.begin(), new_end, ostream_iterator<int>(cout, ","));
	cout << endl;
}

