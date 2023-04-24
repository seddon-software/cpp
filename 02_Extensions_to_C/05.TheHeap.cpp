/*
 *  Local objects are stored on the stack and their lifetimes are therefore restricted to the lifetime of
 *  the function in which they are declared.  If you want a long lived object that persists across function 
 *  calls then you need to use the heap (or globals).  C++ provides the new and delete operators to manage 
 *  objects on the heap.
 * 
 *  new and delete should be called in pairs to avoid memory leakage.
 */

#include <iostream>
using namespace std;


class Point
{
public:
    Point()        // default CTOR
    :
        x(0),
        y(0)
    {
        cout << "Default CTOR" << endl;
    }

    Point(int x0, int y0)
    :
        x(x0),
        y(y0)
    {
        cout << "int int CTOR" << endl;
    }

    ~Point()
    {
        cout << "DTOR" << endl;
    }

private:
    int x;
    int y;
};

int main()
{
    Point* ptr;

    // do something
    ptr = new Point(10, 10);
    // do something

    delete ptr;
}
