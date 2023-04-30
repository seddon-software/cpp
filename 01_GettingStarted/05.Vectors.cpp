/*
 *  In C, all arrays are fixed size, but in C++ vector is a dynamic array in the sense that you can expand the
 *  vector at a later date with the push_back() method:
 * 
 *  It's easy to iterate through a vector using the range based for loop (see below).
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {2, 4, 6, 8, 10};
    v.push_back(12);
    
    // range base for loop
    for(int i : v)
    {
	    cout << i << ", " << flush;
    }
    cout << endl;
}
