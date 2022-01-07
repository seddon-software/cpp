#include <iostream>
//#include <range/v3/all.hpp>
#include <ranges>
#include <vector>
// convert a view to a container

using namespace std;
//using namespace ranges;

int main()
{   
    auto numbers = std::ranges::views::iota(20, 30);
    auto common = std::views::common(numbers);
    // std::views::common only works if the begin iterator and sentinel are the same type
    // this is true for all STL containers 
    auto b = std::ranges::begin(numbers); 
    auto e = std::ranges::begin(numbers); 
    // check iterator and sentinel are of the same type
    cout << "type of begin iterator: " << typeid(b).name() << endl;
    cout << "type of end sentinel:   " << typeid(e).name() << endl;
    auto v = std::vector(std::ranges::begin(common), std::ranges::end(common));
    for(auto i : v) std::cout << i << ",";
    std::cout << std::endl;
}
