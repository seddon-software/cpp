/*
 *  Although you can access the items in a vector using [] brackets, we often use iterators instead.
 *  Not all the classes in the Standard Template Library (STL) support [] because it relies on the
 *  underlying data structure being stored in contiguous memory.  Iterators, on the other hand, are a
 *  generalisation of pointers and supported by all the STL classes.  
 * 
 *  Later, we will see STL collection classes like vector are often used with the algorithms package.
 *  This package is defined in terms of iterators and not in terms of [].
 * 
 *  Thus the key parts of the STL are:
 *          classes
 *          iterators
 *          algorithms
 * 
 *  Each class defines its on iterator type.  For vectors the iterators are of type:
 *          vector<T>::iterator
 * 
 *  To get an iterator to the beginning of the vector use:
 *              i = v.begin()
 * 
 *  and to check we haven't reached the end of the vector use:
 *              i != v.end()
 * 
 *  Note that since iterators are generalised pointers they overload the ++ operator to step through the
 *  collection and overload * to dereference the item pointed at by the iterator.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    vector<string> collection;

    collection.push_back("London");
    collection.push_back("Madrid");
    collection.push_back("New York");
    collection.push_back("Tokyo");
    collection.push_back("Rome");

    vector<string>::iterator i;

    for (i = collection.begin(); i != collection.end() ;  ++i)
    {
        cout << *i << endl;
    }
}

