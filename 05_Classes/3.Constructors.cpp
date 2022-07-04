/*
 *  In the previous examples, we defined an initialize method that had to be called before our object was useable.
 *  This means the user of the class might make an error by calling one the other class methods prematurely.  To overcome this
 *  proble, the language allows you to initialize an object at time of creation using a special method called a constructor (CTOR).
 * 
 *  The code in a constructor will achieve the same thing as our previous Initialize method, however the syntax used differs somewhat.
 *  The constructor is guaranteed to be called at object creation time:
 *                  Point p1(700, 100);       // implicit call to a CTOR
 * 
 *  but note you need to supply the initial parameters directly to the CTOR.  In the CTOR code you must define the so called 
 *  initialization list:
 *                  : // Initialisation List
 *                      x(theX)
 *                      y(theY)
 * 
 *  where each attribute is initialized in a comma separated list using ().  The spaces in the list ar not significan't and are 
 *  often omitted.  In fact it's common to see the whole constructor written in one line: 
 *                      Point::Point(int theX, int theY) : x(theX), y(theY) {}
 * 
 *  Note that in any method (not just CTORs) there exists a 'this' pointer (defined by the compiler) that points at the current 
 *  object in memory.  This 'this' pointer is usually omitted in code, but note that:
 *                      x = x + dx;
 * 
 *  can be written using the more verbose form:
 *                      this->x = this->x + dx

 *  Aside from that, the example is the same as before.
 */

#include <iostream>
using namespace std;

class Point
{
public:
    Point(int, int);
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

Point::Point(int theX, int theY)
:                   // Initialisation List
    x(theX),
    y(theY)
{
}

void Point::MoveBy(int dx, int dy)
{
    x = x + dx;
    // this->x = this->x + dx
    y = y + dy;
}

void Point::WhereAreYou()
{
    cout << "Point is at: " << x
         << ", "            << y
         << endl;
}

int main()
{
    Point p1(700, 100);       // implicit call to a CTOR
    Point p2(100, 300);
    Point p3(600, 600);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();

    p1.MoveBy(10, 10);
    p2.MoveBy(10, 10);
    p3.MoveBy(10, 10);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();
}

