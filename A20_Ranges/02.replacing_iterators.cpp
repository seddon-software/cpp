#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


/*  The range concept defines the requirements of a type that allows iteration over its elements by providing
 *  an iterator and sentinel pair that define the start and end of the range.  A sentinel can be an iterator
 *  in some ranges, but not if the end of the range needs to be computed dynamically.
 * 
 *  Because the sentinel can be an iterator, it follows that all the containers of the STL are themselves ranges.
 * 
 *  In this example, we look at how to sort a vector in two different ways:
 *          1) using begin() and end() iterators
 *          2) using a range
 */

int main() 
{
    { // sort using iterators
        vector<int> vect{-3, 5, 0, 7, -4};
        sort(vect.begin(), vect.end());
        for (auto v: vect) cout << v << ",";
        cout << endl;
    }
    { // sort using ranges
        vector<int> vect{-3, 5, 0, 7, -4};
        std::ranges::sort(vect);
        for (auto v: vect) cout << v << ",";
        cout << endl;
    }
}
