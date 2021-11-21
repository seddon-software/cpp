// https://hannes.hauswedell.net/post/2019/11/30/range_intro/

#include <iostream>
//#include <range/v3/all.hpp>
#include "range/v3/all.hpp"
#include <ranges>
#include <vector>

//using namespace ranges;
//using namespace std;
using ranges::views::iota;
void printVector(std::vector<int>& v)
{
    for (auto i: v) std::cout << i << ",";
    std::cout << std::endl;
}

int main()
{   
    std::vector<int> v = {8, 7, 10, 11, 12, 5, 6, 1, 0, 4, 2, 3, 9};

    // sorting only all elements after the fifth one
    std::sort(v.begin() + 5, v.end()); // sort from element 5
    printVector(v);

    // using non-standard iterators like reverse iterators
    std::sort(v.rbegin(), v.rend());  // reverse sort
    printVector(v);

    // in C++20 you can do the following:
    //   sorting only all elements after the fifth one:
    std::ranges::sort(std::views::drop(v, 5));  // a view consisting of elements of another view (v), 
                                                // skipping the first 5 elements
    printVector(v);

    // sorting in reverse order
    std::ranges::sort(std::views::reverse(v));
    printVector(v);


    // auto const s = std::string{"feel_the_force"};
    // auto words = s | views::split('_'); // [[f,e,e,l],[t,h,e],[f,o,r,c,e]]
    // auto words_cap = words | views::transform([](auto w){
    //     auto head = w | views::take(1) 
    //                   | views::transform([](char c){return std::toupper(c);}); // e.g. [F]
    //     return views::concat(head, w | views::tail); // e.g. [F,e,e,l]
    // }); // [[F,e,e,l],[T,h,e],[F,o,r,c,e]]
    // auto s_camelcase = words_cap | views::join | to<std::string>(); // FeelTheForce
    // std::cout << s_camelcase;
}
