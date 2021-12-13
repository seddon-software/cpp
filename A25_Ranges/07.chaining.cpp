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
    std::vector v1{1, 2, 3, 4, 5, 6};
    // views pipeline
    auto v2 = v1 | std::views::reverse | std::views::drop(1) | std::views::reverse | std::views::drop(1);
    // equivalent nested calls
    auto v3 = std::views::drop(std::views::reverse(std::views::drop(std::views::reverse(v1), 1)), 1);

    print(v1);
    print(v2);
    print(v3);
}