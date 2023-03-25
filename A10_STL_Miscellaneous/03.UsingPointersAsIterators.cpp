#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

/*
 *  Although it is now customary to use STL iterators in C++ code we shouldn't forget that
 *  iterators are generalized pointers.  Conversely, pointers meet all the criteria required
 *  to be defined as iterators themselves and can be used as such.
 * 
 *  We will explore using standard pointers as iterators in this section.
 */

using namespace std;

int main()
{
    // define a C array of floats
	const float cost[] = { 4.44, 5.55, 6.66, 7.77, 8.88, 9.99 };

    // use the copy algorithm to print part of the array
    // cost+2 and cost+5 are float* pointers
    // cost+2: &cost[2]
    // cost+5: &cost[5]
	copy(cost+2, cost+5, ostream_iterator<float>(cout, ","));  // "," is delimeter
	cout << endl;

    // copy array to vector
	vector<float> v(3);
	copy(cost+2, cost+5, v.begin());

    // print vector
	copy(v.begin(), v.end(), ostream_iterator<float>(cout, ","));
    cout << endl;
}
