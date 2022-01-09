#include <iostream>
#include <numeric> //std::iota
#include <vector>

using namespace std;

/*
 *  The iota(first, last, init) template fills the range [first, last) with sequentially increasing 
 *  values, starting with "init" and repetitively evaluating ++init.  The template is very useful for
 *  creating a range of integers, as in the example below:
 */

int main()
{
    vector<int> v(10);          // vector with 10 items
    iota(begin(v), end(v), 50); // 50, 51, 52, ...
    for(auto i : v)
    {
        cout << i << ", ";
    }
    cout << endl;
}