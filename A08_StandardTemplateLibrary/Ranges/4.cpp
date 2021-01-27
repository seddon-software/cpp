#include <iostream>
#include <range/v3/all.hpp>

// https://www.walletfox.com/course/examples_range_v3.php
using namespace ranges;

int main(){   
    auto const s = std::string{"feel_the_force"};
    auto words = s | views::split('_'); // [[f,e,e,l],[t,h,e],[f,o,r,c,e]]
    auto words_cap = words | views::transform([](auto w){
        auto head = w | views::take(1) 
                      | views::transform([](char c){return std::toupper(c);}); // e.g. [F]
        return views::concat(head, w | views::tail); // e.g. [F,e,e,l]
    }); // [[F,e,e,l],[T,h,e],[F,o,r,c,e]]
    auto s_camelcase = words_cap | views::join | to<std::string>(); // FeelTheForce
    std::cout << s_camelcase;
}
