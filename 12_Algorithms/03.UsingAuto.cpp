/*
 *  Here is the same example using "auto" to simplify the code.  Try to use auto wherever you can.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    for(auto i = v.begin(); i != v.end(); ++i)
    {
    	cout << *i << endl;
    }
}
