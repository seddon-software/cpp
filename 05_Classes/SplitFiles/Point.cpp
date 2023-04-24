/*
 *  This file contains the implementations of all the member functions of the Point class.
 *  Note that each method needs to be declared prepended with the Point class name as in:
 *          void Point::Initialise(int theX, int theY) { ... }
 */

#include "Point.h"

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

