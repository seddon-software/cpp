#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

// A key feature of views is that whatever transformation they apply, 
// they do so at the moment you request an element, not when the view is created: lazy evalution.

void print(auto v)
{
    for (auto i: v) cout << i << ",";
    cout << endl;
}

int main()
{
    vector v1{1, 2, 3, 4, 5, 6};
    auto v2 = std::views::reverse(v1);
    print(v1);
    print(v2);
}