/*
 *  Iterators are a generalization of pointers that allow a C++ program to work with STL classes in a 
 *  consistant way.  For example, a vector class object is stored in contiguous memory and supports the []
 *  operator, because this is an efficient operation.  However, the list class doesn't support the [] operator
 *  because the linked list is not stored in contiguous memory.  This means the [] operator can only be used
 *  with a restricted set of STL classes.  Iteraors, however, are available in all STL classes.
 *   
 *  The algorithms library makes extensive use of iterators.  Futher, in C++20, ranges have been introduced 
 *  to simplify still C++ further; a range is defined as a pair of iterators.  For example, one iterator 
 *  defining the start of a range and the other iterator the end of a range.  We will look at ranges later.
 *
 *  Since iterators are an abstraction of pointers, every function template that takes iterators works just as 
 *  well with regular pointers. 
 *
 *  Each STL class provides its own flavour of iterator.  In the example below we use auto to declare the 
 *  iterator i for simplicity, but we could have defined i explicitly as:
 *          vector<int>::iterator i
 * 
 *   Note the use of
 *          i = v.begin()
 *   to get an iterator (generalized pointer) to the start of the vector.
 * 
 *          i != v.end()
 *   to continue until the end of the vector is reached.  Each STL class contains a dummy end item just after the 
 *   last value in the container and v.end() points to this dummy item.
 * 
 *          i++
 *   to step to the next item in the vector.
 * 
 *          *i
 *   to dereference the iterator and access data in the underlying vector.
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector v = {2, 4, 6, 8, 10};

    for(auto i = v.begin(); i != v.end(); ++i)
    {
	    cout << *i << ", " << flush;
    }
    cout << endl;
}
