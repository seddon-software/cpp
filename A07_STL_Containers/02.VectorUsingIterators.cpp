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
 *  The Standard Template Library (STL) provides several collection classes.  The vector class (already 
 *  discussed) supports random access and hence overloads the [] operator.  Other collection classes, such
 *  as List (implemented as a doubly linked list) are not random access and hence do not overload the []
 *  operator.  The designers of the STL wanted to privide as much commonality of use between these 
 *  collection classes, but clearly this can't be done using []s.
 * 
 *  Instead, the designers chose to use iterators.  Every collection class supports iterators.  An iterator
 *  is an object that knows how to traverse (iterate) the given collection - a generalized pointer.  In 
 *  fact the STL has 3 key concepts:
 * 
 *      collections
 *      iterators
 *      algorithms
 * 
 *  The STL defines a number of algorithms for the collections.  The algorithms are all defined in terms 
 *  of iterators.  As we will see later, iterators come in different forms; the vector uses a random 
 *  access iterator, the List a bidirectional iterator and so on.  Normally each collection class provides
 *  a method to obtain an iterator pertinent to the given collection in the form of begin() and end() 
 *  methods.  Then begin() method returns an iterator pointing at the start of the collection, whilst
 *  the end() method points just after the end of the collection (imagine each collection has an virtual
 *  item at its end).
 *
 *  Let's revisit the vector class example using iterators.  Note that since iterators are generalized
 *  pointers, they overload * ++ != to behave in a similar way to C pointers.
 */

int main()
{
    vector<string> collection;

    collection.push_back("London");
    collection.push_back("Madrid");
    collection.push_back("New York");
    collection.push_back("Tokyo");
    collection.push_back("Rome");

    vector<string>::iterator i;     // nested class

    for (i = collection.begin(); i != collection.end() ;  ++i)  // ++ moves to the next item
    {
        cout << *i << endl;  // *i dereferences the iterator
    }
}

