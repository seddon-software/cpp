#include <iostream>
#include <functional>
#include <vector>
using namespace std;

/*
 *  The standard containers (vector<T>, list<T> etc) are designed to work with value semantics; objects 
 *  are copied to the container.  Since references can't be copied, this means T cannot be a reference 
 *  (but can be a pointer).  However reference_wrapper objects are not references, but behave like 
 *  references.  They are frequently used as a mechanism to store references inside standard containers 
 *  which cannot normally hold references. 
 *  
 *  Consider the vector below.  We initialise it with reference_wrapper objects and then, when we modify
 *  the original objects we see the changes propogated to the vector.
 * 
 *  If we pass a reference_wrapper object to a function (f) by value, the reference_wrapper object is
 *  copied, but the copy still wraps the original object.  That being the case, if the copy is modified
 *  the original will also be changed.
 * 
 *  Effectively, the reference_wrapper object contains an internal pointer to the wrapped object.  Hence 
 *  when the reference_wrapper object is copied, the internal pointer is copied and hence the copy of the
 *  reference_wrapper object still wraps the original object.
 * 
 *  You create a reference_wrapper object using std::ref.
 */

void f(auto x)  // pass by value
{
    x += 10;
}

void print(auto v)
{
    for(auto i: v)
    {
        cout << i << ", ";
    }
    cout << endl;
}
int main()
{
    // create a reference_wrapper object
    int i{100};
    auto r = std::ref(i); // r is of type std::reference_wrapper<int>
    // although we pass the reference_wrapper by value, it behaves like we have passed by reference
    f(r);
    cout << r << endl;

	int a = 1, b = 2, c = 3, d = 4;
    // add reference_wrapper objects to vector
    vector<reference_wrapper<int>> v = { a, b, c, d };

    // modify the original objects
    a += 10;
    b += 10;
    c += 10;
    d += 10;

    // the vector will NOT be changed
    print(v);

    // pass reference_wrapper objects by value
	f(ref(a)); f(ref(b)); f(ref(c)); f(ref(d));
    print(v);       // changes v


}
