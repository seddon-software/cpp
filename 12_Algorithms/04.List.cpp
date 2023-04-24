/*
 *  The List class is an implementation of a doubly linked list.  Here is the vector example re-coded
 *  using the List class.  Note that List doesn't support the [] operator and hence we've used iterators
 *  throughout the example.
 *  
 *  You can add to either end of the doubly linked list using:
 *              collection.push_back("Rome");
 *              collection.push_front("London");
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;


int main()
{
    list<string> collection;

    collection.push_back("Madrid");
    collection.push_back("New York");
    collection.push_back("Tokyo");
    collection.push_back("Rome");
    collection.push_front("London");
    
    for (auto i = collection.begin(); i != collection.end() ;  i++)
    {
        cout << *i << endl;
    }
}

