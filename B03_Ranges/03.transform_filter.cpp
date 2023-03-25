#include <iostream>
//#include <algorithm>
//#include <iterator>
#include <vector>
#include <ranges>
using namespace std;
using namespace std::ranges::views;

/*  
 *  C++20 now allows you to define pipelines that contain range adaptors.  A range adaptor is basically, 
 *  an algorithm that takes one or more ranges and return a new “adapted” range.
 * 
 *  In this example, we use iota to define a set of monotonically increasing integers and then use a pipeline
 *  to first filter out integers that are not even and then transform the remaining even integers into their
 *  squares. 
 */

int main()
{
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    for (int i : iota(10, 25)                               // 10, 11, 12 ... 25
               | std::ranges::views::filter(even)           // 10, 12, 14 ... 24
               | std::ranges::views::transform(square))     // 100, 144, 196 ... 576
    {
        cout << i << ' ' << flush;
    }
}