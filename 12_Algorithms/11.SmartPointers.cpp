/*
 *  When we allocate objects on the heap with "new" we must remember to clean them up later with "delete".
 *  Alternatively, we can use smart pointers to automatically clean up the heap.  Note the smart pointer
 *  has the same size as a raw pointer and therefore doesn't increase the memory footprint of the program
 *  appreciably (just the extra code in the smart pointer class).
 * 
 *  The standard library uses "unique_ptr" to track heap based objects.  The smart pointers in this example
 *  are all created on the stack, but this is not a requirement.
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Point
{
public:
    Point(int x, int y):x(x), y(y) 
    {
        cout << "CTOR called on: " << x << ", " << y << endl;
    }
    ~Point() 
    {
        cout << "DTOR called on: " << x << ", " << y << endl;
    }
private:
    int x, y;
};

// unique pointers maintain ownership
// and clean up on exit from a function because they are stack based
void f1()
{
    [[maybe_unused]]
    Point* p1 = new Point{3,4};     // no DTOR called on exit from function
    unique_ptr<Point> u1{new Point{30,40}};
}

void f2()
{
    [[maybe_unused]]
    Point* p2 = new Point{7,8};     // no DTOR called on exit from function
    unique_ptr<Point> u2{new Point{70,80}};
}

void f3()
{
    [[maybe_unused]]
    Point* p3 = new Point{3,9};     // no DTOR called on exit from function
    unique_ptr<Point> u3{new Point{30,90}};
}

int main()
{
    f1();
    f2();
    f3();
}
