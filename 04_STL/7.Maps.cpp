////////////////////////////////////////////////////////////
//
//      Map
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef pair<string, int> Pair;
typedef map<string, int, less<string> > Map;


void Print(const Pair& p) 
{ 
    cout << p.first << ", " << p.second << endl; 
}

/////


int main()
{
    Map theList;
    Map::iterator i;
    
    theList["Steven"] = 25000;
    theList["Mary"] = 18000;
    theList["John"] = 20000;
    theList["Susan"] = 36500;
    theList["Rose"] = 17500;

	string key("Susan");
	i = theList.find(key);
	Print(*i);

    return 0;
}
