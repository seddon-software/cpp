#include <iostream>
//#include <algorithm>
//#include <iterator>
#include <vector>
#include <ranges>
using namespace std;
using namespace std::ranges::views;

// The range concept defines the requirements of a type that allows iteration over its 
// elements by providing an iterator and sentinel that denote the elements of the range.

int main()
{
    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };
 
    for (int i : iota(10, 25)
               | filter(even)
               | std::ranges::views::transform(square)) {
        cout << i << ' ';
    }
}