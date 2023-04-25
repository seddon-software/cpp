/*
 *  Before we continue you should be aware of the copy constructor.  This is a special constructor
 *  that allows a new object to be initialised by copying an old object.  The copy is normally performed
 *  copying each component in turn.
 * 
 *  The signature of the copy constructor is always the same.  For a given class (e.g. Point) the copy
 *  constructor takes only one parameter of the same type as the class (e.g. Point).  Since the object
 *  being copied won't be changed it is declared "const" and passed by reference for efficiency:
 *              Point(const Point&);        // copy CTOR
 * 
 *  Actually you have to use a reference here because if you tried to use a copy as a parameter it
 *  would be a new object and would need to be initialised.  And guess what?  you'd need to use the
 *  copy constructor to do that, and that in turn would then cause a recursive loop of calls to the 
 *  copy contructor which would never end.
 */

#include <iostream>
using namespace std;

class Point
{
public:
    Point(int, int);
    Point(const Point&);        // copy CTOR
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

// CTOR(int, int)
Point::Point(int theX, int theY): x(theX), y(theY) {}

// Copy CTOR
Point::Point(const Point& old): x(old.x), y(old.y) {}

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
    Point p(700, 100);       // calls CTOR(int, int)
    Point q(p);              // calls CTOR(const Point&) which is the copy CTOR
    q.MoveBy(1, 1);
    q.WhereAreYou();
}

