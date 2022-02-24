#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

/*
 *  Here we present some further transformations on views.  Note the original range does get modified.
 */

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
        vector v1{99, 99, 99, -3, 5, 0, 7, -4, 12, -2};  // template parameter deduced as int
        sort(v1.begin() + N, v1.end());                   // modify v1: only sort from item 2 to end
        print(v1);
    }
    { // using ranges
        vector v2{99, 99, 99, -3, 5, 0, 7, -4, 12, -2};
        auto v = std::views::drop(v2, N);               // create view of v2: only from item 2 to end
        ranges::sort(v);
        print(v);
        print(v2);
    }
    { // reverse sort
        vector v3{77, 88, 99, -3, 5, 0, 7, -4, 12, -2};
        auto v = views::reverse(v3);                    // create reverse view of v3
        ranges::sort(v);        
        print(v);
        print(v3);
    }
}