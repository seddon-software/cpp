#include <iostream>
//#include <algorithm>
#include <iterator>
#include <vector>
#include <range/v3/all.hpp>
//using namespace std;
//using namespace ranges;
using ranges::views::transform;

int main()
{
	std::vector<int> v(30);
	int start = 22;
	ranges::generate(v.begin(), v.end(), [&]() { return start++; });
    std::cout << "original range (starting at 23):" << std::endl;
    for (auto i: v) std::cout << i << " ";
    std::cout << std::endl;

    {
        std::cout << "create a view of items in range divisible by 5" << std::endl;
        auto range = v | ranges::views::filter([](int x){return x % 5 == 0;});
        for (auto v: range) std::cout << v << " ";
        std::cout << std::endl;
    }
    {
        std::cout << "create a view of 5 * range" << std::endl;
        auto range = v | ranges::views::transform([](int x){return x * 5;});
        for (auto v: range) std::cout << v << " ";
        std::cout << std::endl;
    }
}

