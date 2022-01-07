////////////////////////////////////////////////////////////
//
//      Vector - using iterators
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*  
 *  STL collections can be initialized like other C++ objects.  In this example we use {} intialization.
 *  However, if we want to use string objects in the collection as opposed to const char* arrays and
 *  hence we use:
 *      {"London"s, "Madrid"s, "New York"s, "Tokyo"s, "Rome"s}
 *  "s is the operator" overload which automatically converts const char*s to mutable string objects.
 *  
 *  Other points to note in this example:
 *      1. use auto to declare the iterator
 *      2. the range based loop iterates through the collection, but the compiler still calls begin() 
 *          and end() behind the scenes. 
 */

int main()
{
    vector collection {"London"s, "Madrid"s, "New York"s, "Tokyo"s, "Rome"s};

    for (auto i = collection.begin(); i != collection.end() ;  ++i)
    {
        cout << *i << endl;
    }

    for (auto s : collection)  // this uses begin() and end() behind the scenes
    {
        cout << s << endl;
    }
}

