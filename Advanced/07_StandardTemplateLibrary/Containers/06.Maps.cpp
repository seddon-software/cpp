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
    
    theList["Steven"] = 25000;
    theList["Mary"]   = 18000;
    theList["John"]   = 20000;
    theList["Susan"]  = 36500;
    theList["Rose"]   = 17500;

    for(i = theList.begin(); i != theList.end(); ++i)
    {
        Print(*i);
    }
    return 0;
}
