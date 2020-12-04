////////////////////////////////////////////////////////////
//
//      Using Constructors
//
////////////////////////////////////////////////////////////

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

