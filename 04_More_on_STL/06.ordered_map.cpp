/*
 *  This shows an example of using the map class which maintains order of the items in the collection.
 *  You'll note that the code looks very similar to that of the unordered_map, but the underlying 
 *  implementation is very different.
 * 
 *   At the end of this example we print out the collection in lexical order of keys.
 */

#include <iostream>
#include <string> 
#include <map>
using namespace std;

int main()
{
    map<string, int> salaries =
    {
        {"Steven", 25000},
        {"Mary",   18000}
    };
    // [] is overloaded to make insertions simple
    salaries["John"]   = 20000;
    salaries["Susan"]  = 36500;
    salaries["Rose"]   = 17500;

    // print out the collection in lexical order of keys
    cout << "ordered map: " << endl;
    for(auto [name, salary] : salaries)
    {
        cout << name << ", " << salary << endl;
    }
}
