#include <iostream>
//#include <algorithm>
//#include <iterator>
#include <vector>
#include <ranges>
using namespace std;
using namespace std::ranges::views;


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