////////////////////////////////////////////////////////////
//
//      Map
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>
#include <typeinfo>



using namespace std;

// using can replace typedefs:
//      typedef pair<const string, int> PAIR;
//      typedef map<const string, int, less<string>> MAP;
using PAIR = pair<const string, int>;
using MAP = map<const string, int, less<string>>;


ostream& operator<<(ostream& os, const PAIR& p)
{
    os << p.first << ", " << p.second; 
    return os;
}

/////

int main()
{
/*
    map::insert does not modify the map if key exists
    map::operator[] always overwrites even if the key exists
*/
    MAP theList;
    // use insert for new entries
    // we need to insert pair<string, int>
    theList.insert(PAIR("Mary", 18000));        // C++17: compiler infers pair types(const char*, int) from CTOR
    theList.insert(PAIR("John", 20000));
    theList.insert(PAIR("Susan", 36500));
    theList.insert(PAIR("Rose", 17500));
    theList.insert(PAIR("Steven", 26000));

    // use operator[ ] to update elentries
    theList["Mary"]   = 18050;
    theList["John"]   = 20050;
    theList["Susan"]  = 36550;
    theList["Rose"]   = 17550;
    theList["Steven"] = 26050;

    for(auto i = theList.begin(); i != theList.end(); ++i)
    {
        cout << *i << endl;
    }
}
