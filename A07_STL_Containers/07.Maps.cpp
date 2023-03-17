/*  
 *  The map class is used to store key-value pairs in a red-black binary tree.  The implementation
 *  includes an order which can be specified as an optional comparison template.  By default the
 *  comparision template is:
 *          less<string>
 *  which orders based on a lexical comparison.
 * 
 *  The key value pairs in the map are represented by the pair template which is implied by the 
 *  <map> header file, but actually defined in <utility>.  The pair template defines two components:
 *  first and second.
 */

#include <iostream>
#include <string>
#include <utility>
#include <map>


using namespace std;

void Print(const pair<string, int>& p) 
{ 
    cout << p.first << ", " << p.second << endl; 
}

/////


int main()
{
    map<string, int, less<string>> theMap;
    
    theMap["Steven"] = 25000;
    theMap["Mary"]   = 18000;
    theMap["John"]   = 20000;
    theMap["Susan"]  = 36500;
    theMap["Rose"]   = 17500;

    for(auto i = theMap.begin(); i != theMap.end(); ++i)
    {
        Print(*i);
    }
}
