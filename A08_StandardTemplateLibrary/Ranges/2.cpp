#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <range/v3/all.hpp>
//using namespace std;
//using namespace ranges;
//using ranges::views::transform;

int main()
{
    auto const v = std::vector<int> {3,2,1};
    auto range = v | ranges::views::transform(
                         [](int x){return 2*x;}); // [6,4,2]
    for (auto v: range) std::cout << v << " ";
    std::cout << std::endl;
}
