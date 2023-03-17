/*  
 *  set is an associative container that contains a sorted set of unique objects called keys. Sorting is done 
 *  using a key comparison function.  Search, removal, and insertion operations have O(logN) complexity. Sets 
 *  are usually implemented as red-black trees.
 * 
 *  Here's a example to show how to uses sets; we've used the std::less template to define the comparator
 *  function.  The less template uses the operator<() function for template parameter (i.e. string comparison).
 * 
 *  Note the use of:
 *          pair<SET::iterator, bool> result;
 * This allows us to check if an insert works or fails because of a duplicate key
 */

#include <iostream>
#include <string>
#include <set>

using namespace std;

// note: a set must define a comparator because elements are ordered
using SET = set<string, less<string>>;

//////

int main()
{
    SET theSet;
        
    // insert keys
    theSet.insert("Steven"s);
    theSet.insert("Mary"s);
    theSet.insert("John"s);

    // try to insert a duplicate key
    pair<SET::iterator, bool> result;   // result.second will be false on failure
    result = theSet.insert("Steven"s);
    if(result.second == false) 
    {
        cout << "insertion failed - duplicate entry" << endl;
    }

    // continue to insert
    theSet.insert("Susan"s);
    theSet.insert("Rose"s);

    // iterate through the list, noting items are in lexical order
    for (auto i = theSet.begin(); i != theSet.end(); i++)
    {
        cout << *i << endl; 
    }
    for (const auto& s: theSet)
    {
        cout << s << endl; 
    }
}
