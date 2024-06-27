/*
 *  Maps are an implementation of binary trees.  They are similar to hash maps except they maintain an 
 *  order.  The Map class is templated with 3 types:
 *              map<string, int, less<string>>
 *                     ^     ^        ^
 *                    key  value   comparator
 * 
 *  Note, we use typedefs to simplify the code:
 *              using Pair = pair<string, int>;
 *              using Map = map<string, int, less<string>>;
 *  
 *  where "using" is the modern replacement for typedefs.  The old way of doing this was:
 *              typedef pair<string, int> Pair;
 *              typedef map<string, int, less<string>> Map;
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

using Pair = pair<string, int>;
using Map = map<string, int, less<string>>;

/////

int main()
{
    MAP theList;
    
    theList["Steven"] = 25000;
    theList["Mary"] = 18000;
    theList["John"] = 20000;
    theList["Susan"] = 36500;
    theList["Rose"] = 17500;

	string key("Susan");
	auto i = theList.find(key);
    cout << "key=" << i->first << ",value=" << i->second << endl; 
}
