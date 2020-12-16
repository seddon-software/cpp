////////////////////////////////////////////////////////////
//
//      Point implementation
//
////////////////////////////////////////////////////////////

#include "Point.hpp"

void Point::Initialise(int theX, int theY)  // method OR member function
{
    x = theX;
    y = theY;
}

void Point::MoveBy(int dx, int dy)
{
    x = x + dx;
    y = y + dy;
}

void Point::WhereAreYou()
{
    cout << "Point is at: " << x
         << ", "            << y
         << endl;
}

