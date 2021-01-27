////////////////////////////////////////////////////////////
//
//      Using Constructors
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Triangle
{
public:
    Triangle(int, int);
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

Triangle::Triangle(int theX, int theY)
:                   // Initialisation List
    x(theX),
    y(theY)
{
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

int main()
{
    Triangle p1(700, 100);       // implicit call to a CTOR
    Triangle p2(100, 300);
    Triangle p3(600, 600);

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

