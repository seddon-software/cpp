#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

/*  In this example we examine how std::vector works when we use the push_back method.  All the STL 
 *  classes use copying semantics and we can see this in practice below.  Note that when we attempt
 *  to push_back a temporary the vector will invoke the move constructor for efficiency.
 * 
 *  In the example, the vector is declared with size 6, so each of the slots is filled with an object
 *  that gets default constructed.
 */

struct MyClass
{
    MyClass() 
    { 
    	cout << "default CTOR: " << this << endl;
    }
    MyClass(MyClass&&) noexcept
    {
    	cout << "Move: " << this << endl;
    }
    MyClass(const MyClass&)
    {
    	cout << "Copy: " << this << endl;
    }
};


int main()
{
    // use the debugger to single step through this code ... 
    // ... note the use of system("clear") to clear the screen between push_backs
    vector<MyClass> v(6);   // default construct 6 objects
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
    system("clear");
    MyClass m1, m2, m3;
    system("clear");
    v.push_back(m1);        // copy l-value
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
    system("clear");
    v.push_back(m2);        // copy l-value
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
    system("clear");
    v.push_back(m3);        // copy l-value
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
    system("clear");
    v.push_back(MyClass()); // move r-value
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
    system("clear");
    v.push_back(MyClass()); // move r-value
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
    system("clear");
    v.push_back(MyClass()); // move r-value
    cout << "capacity=" << v.capacity() << ", size=" << v.size() << endl;
}
