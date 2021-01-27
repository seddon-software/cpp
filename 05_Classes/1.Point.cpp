////////////////////////////////////////////////////////////
//
//      Point class
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Triangle
{
public:
    void Initialise(int, int);
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

void Triangle::Initialise(int theX, int theY)  // method OR member function
{
    x = theX;
    y = theY;
}

void Triangle::MoveBy(int dx, int dy)
{
    // (*this).x = (*this).x + dx;
    // this->x = this->x + dx;
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
    Triangle p1;       // p1 IS AN object
    Triangle p2;
    Triangle p3;

    p1.Initialise(700, 100);
    p2.Initialise(100, 300);
    p3.Initialise(600, 600);

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