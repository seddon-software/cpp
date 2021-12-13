#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

void print(auto v)
{
    for (auto i: v) cout << i << ",";
    cout << endl;
}

int main()
{
    // sort after first N elements
    int N = 2;
    { // using iterators
        vector v{99, 99, 99, -3, 5, 0, 7, -4, 12, -2};  // template parameter deduced as int
        sort(v.begin() + N, v.end());
        print(v);
    }
    { // using ranges
        vector v{99, 99, 99, -3, 5, 0, 7, -4, 12, -2};
        ranges::sort(views::drop(v, N));
        print(v);
    }
    { // reverse sort
        vector v{77, 88, 99, -3, 5, 0, 7, -4, 12, -2};
        ranges::sort(views::reverse(v));
        print(v);
    }
}