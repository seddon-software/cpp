#include <vector>
#include <ranges>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    std::vector vec { -1, 5, -2, -7, 4, -9 };
    auto print = [](int i) { std::cout << i << ", "; };
    std::cout << "with abs() projection: \n";
    std::ranges::sort(vec, {}, [](int i) { return std::abs(i); }); // {} defaults to ranges::less
    std::ranges::for_each(vec, print);
}
