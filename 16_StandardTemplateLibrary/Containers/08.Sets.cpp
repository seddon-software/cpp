////////////////////////////////////////////////////////////
//
//      Set - duplicate inserts
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <set>

using namespace std;

typedef pair<string, int> PAIR;
typedef set<PAIR, less<PAIR> > SET;
// note set must define a comparator because elements
// are sorted

void Print(const PAIR& p) 
{ 
    cout << p.first << ", " << p.second << endl; 
}

//////

int main()
{
    SET theSet;
    SET::iterator i;
        
    // insert pairs
    theSet.insert(make_pair(string("Steven"), 25000));
    theSet.insert(make_pair(string("Mary"),   18000));
    theSet.insert(make_pair(string("John"),   20000));

    // try to insert a duplicate
    pair<SET::iterator, bool> result;
    result = theSet.insert(make_pair(string("Steven"), 25000));
    if(result.second == false) 
    {
        cout << "insertion failed - duplicate entry" << endl;
    }

    // continue to insert
    theSet.insert(make_pair(string("Susan"),  36500));
    theSet.insert(make_pair(string("Rose"),   17500));

    // iterate through the list
    for (i = theSet.begin(); i != theSet.end(); i++)
    {
        Print(*i);
    }

    return 0;
}
