////////////////////////////////////////////////////////////
//
//      List - iterators
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <list>

using namespace std;


int main()
{
    list<string> collection;

    collection.push_back("London");
    collection.push_back("Madrid");
    collection.push_back("New York");
    collection.push_back("Tokyo");
    collection.push_back("Rome");
    
    list<string>::iterator i;

    for (i = collection.begin(); i != collection.end() ;  i++)
    {
        cout << *i << endl;
    }
}

