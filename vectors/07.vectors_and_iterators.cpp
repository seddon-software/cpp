/*
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector v = {2, 4, 6, 8, 10};

    for(auto i = v.begin(); i != v.end(); ++i)
    {
	    cout << *i << ", " << flush;
    }
    cout << endl;
}
