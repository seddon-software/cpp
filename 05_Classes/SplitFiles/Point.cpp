////////////////////////////////////////////////////////////
//
//      Point implementation
//
////////////////////////////////////////////////////////////

#include "Point.h"

void Triangle::Initialise(int theX, int theY)  // method OR member function
{
    x = theX;
    y = theY;
}

void Triangle::MoveBy(int dx, int dy)
{
    x = x + dx;
    y = y + dy;
}

void Triangle::WhereAreYou()
{
    cout << "Point is at: " << x
         << ", "            << y
         << endl;
}

