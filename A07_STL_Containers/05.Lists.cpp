/*
 *  We can use iterators with other collection classes.  If we use List collection class, the header 
 *  file has changed and vector has been replaced by list.   These are the only changes to the code, 
 *  but the implementation is very different: we are now working with a doubly linked list instead of a 
 *  dynamic array.
 */

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
    
    for (auto i = collection.begin(); i != collection.end() ;  i++)
    {
        cout << *i << endl;
    }
}

