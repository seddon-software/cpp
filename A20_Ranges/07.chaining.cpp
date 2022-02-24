#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

/*
 *  In this example we use drop in a pipeline.  With v2,
 *              std::views::drop(1)
 *  drops the first item from the view after it has been reversed and then reverses and drops again, thereby
 *  dropping the first and last items from the view.
 * 
 *  With v3 we show and set of nested views which achieve the same thing.
 * 
 */

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