////////////////////////////////////////////////////////////
//
//      Map
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef pair<string, int> PAIR;
typedef map<string, int, less<string> > MAP;


void Print(const PAIR& p) 
{ 
    cout << p.first << ", " << p.second << endl; 
}

/////


int main()
{
    MAP theList;
    MAP::iterator i;

    // use insert for new elentries
    theList.insert(MAP::value_type("Mary", 18000));
    theList.insert(MAP::value_type("John", 20000));
    theList.insert(MAP::value_type("Susan", 36500));
    theList.insert(MAP::value_type("Rose", 17500));
    theList.insert(MAP::value_type("Steven", 26000));

    // use operator[ ] to update elentries
    theList["Mary"]   = 18050;
    theList["John"]   = 20050;
    theList["Susan"]  = 36550;
    theList["Rose"]   = 17550;
    theList["Steven"] = 26050;

    for(i = theList.begin(); i != theList.end(); ++i)
    {
        Print(*i);
    }
    return 0;
}
