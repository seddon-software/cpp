////////////////////////////////////////////////////////////
//
//      Inline member functions
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Point
{
public:
    void Initialise(int theX, int theY)  // implicit inline
    {
        x = theX;
        y = theY;
    }
    void MoveBy(int dx, int dy)
    {
        x = x + dx;
        y = y + dy;
    }

    void WhereAreYou()
    {
        cout << "Point is at: " << x
             << ", "            << y
             << endl;
    }
private:
    int x;
    int y;
};



int main()
{
    Point p1;       // p1 IS AN object
    Point p2;
    Point p3;

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

