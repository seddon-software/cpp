/*
 *  Local objects are stored on the stack and their lifetimes are therefore restricted to the lifetime of
 *  the function in which they are declared.  If you want a long lived object that persists across function 
 *  calls then you need to use the heap (or globals).  C++ provides the new and delete operators to manage 
 *  objects on the heap.
 * 
 *  new and delete should be called in pairs to avoid memory leakage.
 * 
 *  Note the print() method is declared as const:
 *              void print() const
 *  This rather awkward construct tells the compiler that this function will not modify *this.
 */

#include <iostream>
using namespace std;


class Point
{
public:
    Point(): x(0),y(0)        // default CTOR
    {
        cout << "Default CTOR" << endl;
    }

    Point(int x0, int y0) : x(x0),y(y0)
    {
        cout << "int int CTOR" << endl;
    }

    void increment()
    {
        x++;
        y++;
    }

    void print() const
    {
        cout << "Point: [" << x << "," << y << "]\n";
    }

    ~Point()
    {
        cout << "DTOR" << endl;
    }

private:
    int x;
    int y;
};

void useThePointObject1(Point* p)
{
    p->increment();
}

void useThePointObject2(const Point* p)
{
    p->print();
}

int main()
{
    Point p{};      // p is stack based; calls default CTOR
    Point* ptr;
    ptr = new Point(10, 10);  // *ptr is heap based
    // heap based objects remain alive until delete called
    useThePointObject1(ptr);
    useThePointObject2(ptr);

    // time to destroy heap based object
    delete ptr;
}
