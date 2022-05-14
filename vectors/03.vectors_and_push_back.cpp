/*
 *  In addition to initialising a vector, you can expand the vector at runtime using the push_back() method:
 *              v.push_back(2);
 * 
 *  This is by far the most common method used with vectors.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);

    for(auto i : v)
    {
	    cout << i << ", " << flush;
    }
    cout << endl;
}
