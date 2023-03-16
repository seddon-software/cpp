/*
 *  Here we pass a vector of tuple to a function by constant reference.  Note that in the for range loop we 
 *  declare card as:
 *              for(const auto& card : h) { ...}
 * 
 *  Note that the const is already implied by using "auto", but it's better to be explicit rather than implicit.
 *  Thus we could have written:
 *              for(auto& card : h) { ...}
 *  instead.
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

void print_hand(const auto& h)
{
    for(const auto& card : h)
    {
        cout << get<0>(card) <<" of " << get<1>(card) << endl;
    }
}

int main()
{
    vector<tuple<string, string>> hand = 
    {
        {"five", "spades"}, 
        {"ace", "diamonds"}, 
        {"queen", "clubs"},
        {"three", "diamonds"}, 
        {"queen", "hearts"}
    }; 

    hand.push_back({"seven", "diamonds"});
    print_hand(hand);
}
