////////////////////////////////////////////////////////////
//
//      Map
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <map>
#include <typeinfo>

using namespace std;



using PAIR = pair<const string, int>;
using MAP = map<const string, int, less<string>>;

/*
 *  Inserting elements in a map can be achieved using [] or the insert method:
 *      map::operator[] always overwrites even if the key exists
 *      map::insert does not modify the map if key exists
 * 
 *  The return from insert indicates whether or not the insertion occured.  C++17 introduced
 *  insert_or_assign() and try_emplace() which effectively replaced both of the previous methods.
 *  These methods use move semantics to improve modifying maps.
 * 
 *  map::insert_or_assign() replaces map::operator[] and will always modify the map
 *  map::try_emplace() replaces map::insert and will update if the keys is new
 */

ostream& operator<<(ostream& os, const PAIR& p)
{
    os << p.first << ", " << p.second; 
    return os;
}

void wasInserted_or_Assigned(auto result)
{
    if(result.second)
        cout << "inserted: key is new" << endl;
    else
        cout << "assigned: key exists" << endl;
}

void wasInsertedInPlace(auto result)
{
        if(result.second)
            cout << "insertion in place succeeded: key is new" << endl;
        else
            cout << "insertion in place failed: key exists" << endl;
}

/////

int main()
{
    MAP theList;

    // insert_or_assign
    theList.insert_or_assign("Mary", 18000);
    theList.insert_or_assign("John", 20000);
    theList.insert_or_assign("Susan", 36500);
    theList.insert_or_assign("Rose", 17500);

    // new keys will be inserted
    {
        auto result = theList.insert_or_assign("Steven", 26000);
        wasInserted_or_Assigned(result);
    }

    // old keys will cause values to be reassigned
    {
        auto result = theList.insert_or_assign("Steven", 27000);
        wasInserted_or_Assigned(result);
    }

    // try_emplace() never overwrites existing keys
    {
        auto result = theList.try_emplace("Mary", 18050);
        wasInsertedInPlace(result);
    }

    // try_emplace() updates when using a new key
    {
        auto result = theList.try_emplace("George", 32000);
        wasInsertedInPlace(result);
    }
}
