#include <iostream>
#include <range/v3/all.hpp>

using namespace ranges;

int main(){   
    auto const v = std::vector<uint8_t> {1,1,1,0};
    auto r_rev = v | views::reverse; // [0,1,1,1]
    auto r_int = views::iota(0, distance(v)); // [0,1,2,3]
    auto r_pow = r_int | views::transform([](int x){
                                return (2 << x) >> 1;}); // [1,2,4,8]
    auto val = inner_product(r_rev,r_pow,0); // 0*1+1*2+1*4+1*8 = 14
    std::cout << val;
}
