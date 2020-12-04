////////////////////////////////////////////////////////////
//
//      List - find algorithm
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

list<string> collection;

void FindInCollection(const string& city)
{
    list<string>::iterator i;

    i = find(collection.begin(), collection.end(), city);
    if (i != collection.end())
        cout << *i << endl;
    else
        cout << "Not found" << endl;
}

int main()
{
	string newYork("New York");
	string beijing("Beijing");

    collection.push_back("London");
    collection.push_back("Madrid");
    collection.push_back("New York");
    collection.push_back("Tokyo");
    collection.push_back("Rome");

	FindInCollection(newYork);
	FindInCollection(beijing);
}






