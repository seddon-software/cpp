/*
 *  vectors are very versatile; they can hold many different types (but not at the same time).  In this example
 *  we place tuples (cards) inside our vector. 
 * 
 *  Notice how the compiler makes it very easy to add an extra card to the vector:
 *              hand.push_back({"seven", "diamonds"});
 * 
 *  The compiler knows the vector contains tuples, so
 *              {"seven", "diamonds"}
 * 
 *  is interprted as a tuple (without having to declare it explicitly).
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

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

    for(auto& card : hand)
    {
        cout << get<0>(card) <<" of " << get<1>(card) << endl;
    }
}
