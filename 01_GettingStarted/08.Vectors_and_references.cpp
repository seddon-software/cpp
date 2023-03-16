/*
 *  When operating on a vector you can iterate through the collection using a reference:
 *              for(auto& i : v)
 *              {
 *	                i *= 2;
 *              }
 *
 *  By using an auto reference, i becomes an alias to the vector and hence allows you to modify the 
 *  contents of the vector:
 *              for(auto& i : v)
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

    for(auto& i : v)
    {
	    i *= 2;
    }

    for(auto i : v)
    {
	    cout << i << ", " << flush;
    }
    cout << endl;
}
