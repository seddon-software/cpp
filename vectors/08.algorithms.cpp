/*
 */

#include <iostream>
#include <vector>
#include <algorithm>        // for transform
#include <numeric>          // for accumulate
using namespace std;

auto double_it(int x)
{
    return x * 2;
}

void print(string name, vector<int>& v)
{
    cout << name << " = ";
    for(auto i : v)
    {
	    cout << i << ", " << flush;
    }
    cout << endl;
}

int main()
{
    vector<int> v1 = {2, 4, 6, 8, 10};
    vector<int> v2(5);

    print("v1", v1);

    cout << "transform v1 to v2 by doubling" << endl;
    transform(v1.begin(), v1.end(), v2.begin(), double_it);
    print("v2", v2);

    vector<int> v3(5);
    cout << "reverse copy v2 to v3" << endl;
    reverse_copy(v2.begin(), v2.end(), v3.begin());
    print("v3", v3);

    cout << "add up all items in v3" << endl;
    int total = accumulate(v3.begin(), v3.end(), 0);
    cout << "Total = " << total << endl;
}
