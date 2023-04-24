/*
 *  As mentioned earlier, the STL classes work with the algorithms package.  A good example algorithm is
 *  the find algorithm shown below.  The find algorithm takes 3 parameters:
 *              collection.begin()      : start of search range
 *              collection.end()        : end of search range
 *              city                    : item to search for
 *              return value            : iterator to item found in the collection
 *  
 *  If the find succeeds the it returns an iterator to the item in the collection.  If the call fails to find
 *  the item then it returns and iterator to the end() of the collection.
 */

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






