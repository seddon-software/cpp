////////////////////////////////////////////////////////////
//
//      Map
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>

using namespace std;

// typedef pair<string, int> PAIR;
// typedef map<string, int, less<string>> MAP;
using PAIR = pair<string, int>;
using MAP = map<string, int, less<string>>;


ostream& operator<<(ostream& os, const PAIR& p)
{
    os << p.first << ", " << p.second; 
    return os;
}

/////


int main()
{
    MAP theList;
    MAP::iterator i;

    // use insert for new entries
    // we need to insert pair<string, int>
    //   so can also use value_type or make_pair 
    theList.insert(PAIR("Mary", 18000));
    theList.insert(MAP::value_type("John", 20000));
    theList.insert(MAP::value_type("Susan", 36500));
    theList.insert(make_pair("Rose", 17500));
    theList.insert(make_pair("Steven", 26000));

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
