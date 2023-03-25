#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

/*
 *  Note that while views do not own their elements, they do not change the mutability of underlying data. 
 
 *  Here, in our first example, we create a view that contains the even elements of the range.  We iterate over
 *  this view, subtracting 100 from each item.  Those elements of the original range that are also present in 
 *  the view will also be changed.
 * 
 *  In the second example, we create a view that excludes the first and last elements of the range.  When we
 *  sort the view, the underlying range that is mapped by the view is also changed.  The first and last elements of 
 *  the range maintain their original positions because they were not part of the view.
 */

void print(auto v)
{
    for (auto i: v) cout << i << ",";
    cout << endl;
}

void example1()
{
    std::vector<int> v = {100, 101, 102, 103, 104, 105, 106, 107};
    auto even = [](std::integral auto x) { return x % 2 == 0; };
    for (auto& vw : v | std::ranges::views::filter(even)) 
    {
        vw -= 100;
    }
    print(v);
}

void example2()
{
    std::vector<int> v = {107, 106, 105, 104, 103, 102, 101, 100};
    // sort the view, the view excludes the first and last elements of the range
    ranges::sort(std::ranges::subrange(v.begin()+1, v.end()-1), {}, {});
    // the underlying range is mutated, but not the two elements not present in the view
    print(v);
}

int main()
{
    example1();
    example2();
}