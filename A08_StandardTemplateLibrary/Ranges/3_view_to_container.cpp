#include <iostream>
#include <range/v3/all.hpp>

// convert a view to a container

//using namespace std;
//using namespace ranges;

int main()
{   
    auto x = ranges::views::iota(20, 30);
    auto v = x | ranges::to<std::vector>();
    for(auto i : v) std::cout << i << ",";
    std::cout << std::endl;
}
