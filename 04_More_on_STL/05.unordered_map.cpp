/*
 *  Back in the 90s C++ introduced a number of collecion classes including the map class.  The map class
 *  is an implementation of a red-black binary tree and caters for collections of key-value pairs.  Often
 *  collections of key-value pairs are often implemented as hash maps.
 *  
 *  Suprisingly hash maps were absent from the earlier standard.  This was remedied in C++11 and the 
 *  unordered_map was introduced which is an implementation of a hash map.
 * 
 *  We are usually interested in the speed of interacting with these collection classes.  With that in mind,
 *  operation complexities are as follows:
 * 
 *    map:            search, removal, and insertion operations have O(log N) complexity.
 *    unordered_map:  search, removal, and insertion operations have O(N) complexity (i.e constant speed).
 * 
 *  From the above we see the map is slightly slower than the unordered_map, but as the names suggest this
 *  is because map maintains an order whereas the hash map doesn't.
 */

#include <iostream>
#include <string> 
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> salaries = 
    {
        {"Steven", 25000},
        {"Mary",   18000}
    };

    // [] is overloaded to make insertions simple
    salaries["John"]   = 20000;
    salaries["Susan"]  = 36500;
    salaries["Rose"]   = 17500;

    // print out the collection (note keys will be in a random order)
    cout << "unordered map: " << endl;
    for(auto [name, salary] : salaries)
    {
        cout << name << ", " << salary << endl;
    }
}
