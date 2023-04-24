/*
 *  A more interesting algorithm is find_if:
 *              collection.begin()      : start of search range
 *              collection.end()        : end of search range
 *              LessThan21K             : function callback for each item
 *              return value            : iterator to item found in the collection
 * 
 *  The idea behind find_if is to callback on a function specified as its last parameter.  find_if calls
 *  our function with each item in turn.  We return true if the item is the one we want and false otherwise.  
 *  Such a callback function is called a binary predicate (returns true or false).
 * 
 *  The items in this example are "pair" objects, i.e. key, value pairs.  We use a map (binary tree) to store
 *  our pair items.
 *  
 *  Note that using a callback like this appears to be a little unflexible because it only allows you to check
 *  for a fixed set of conditions (i.e, a salary less than 21K).  If we want to check for a many different 
 *  sets of conditions we would have to write a whole set of callback functions to match.
 * 
 *  You might think that in this example we could pass the salary as an additional parameter.  However, the 
 *  code for find_if is essentially:
 * 
 *              Iterator find_if(Iterator first, Iterator last, Predicate fp)
 *              {
 *                  while (first != last && !fp(first))
 *   	                ++first;
 *                  return first;
 *              }
 * 
 *  The callback is:
 *              fp(first)
 *  
 *  and this only takes one parameter.  If we want to make things more flexible we need to find a way of
 *  smuggling in the salary, but we can't use an additional parameter!
 * 
 *  The solution to this conundron is to write a functor!  See the next example for details.
 */

#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<string, int> Pair;

void Print(Pair& p)
{
    cout << p.first << ", " << p.second << endl; 
}


bool LessThan21K(const Pair& p)
{
    if (p.second < 21000)
        return true;
    else
        return false;
}

/////

int main()
{
    list<Pair> collection;
    list<Pair>::iterator i;

    Pair item1 = make_pair("Steven", 25000);
    Pair item2 = make_pair("Mary",   28000);
    Pair item3 = make_pair("John",   20000);
    Pair item4 = make_pair("Susan",  36500);
    Pair item5 = make_pair("Rose",   17500);

    collection.push_back(item1);
    collection.push_back(item2);
    collection.push_back(item3);
    collection.push_back(item4);
    collection.push_back(item5);
    
    // search for first item that earns less than $21,000
    cout << endl << "Searching for first item that earns less than 21,000" << endl;
    i = find_if(collection.begin(), collection.end(), LessThan21K);
    Print(*i);
}
