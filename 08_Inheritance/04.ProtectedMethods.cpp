/*
 *  An earlier example introduced a Snap class that snapped points to a grid.  In that example the base 
 *  class attributes were made protected in order that the Snap class could access its x and y attributes.
 *  
 *  In this example we try an alternative strategy of providing a protected method in the base class to do
 *  the snapping.  We make it protected so that it is accessible from Snap but not from client code (the 
 *  main program).
 * 
 *  Note: We want to print the color of the ColoredPoint with cout.  This necessitates providing a second
 *  operator<<() overload and ensuring we don't up making an infinitely recursive call (using a cast).
 */

#include <iostream>
#include <string>
using namespace std;


class Point
{
public:
    Point(int x0 = 0, int y0 = 0) 
    :
        x(x0),
        y(y0)
    {
    }

    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << p.x << "," << p.y;
        return out;
    }

    void MoveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
protected:
    void SnapToGrid()
    {
        x = x / 10 * 10;
        y = y / 10 * 10;
    }
private:
    int x;
    int y;
};

/////

class ColoredPoint : public Point
{
public:
    ColoredPoint(int x0 = 0, int y0 = 0, const string& s = "White"s)
    :
        Point(x0, y0),
        color(s)
    {
        SnapToGrid();       // can only access protected method from here 
    }

    friend ostream& operator<<(ostream& out, const ColoredPoint& p)
    {
        out << (Point)p;        // call the overload that takes a Point and not a ColoredPoint
        out << ", " << p.color;
        return out;
    }

    void ChangeColor(const string& newColor)
    {
        color = newColor;
    }
private:
    string color;
};

/////

int main()
{
    Point         p(45, 67);
    cout << p << endl;

    ColoredPoint cp(33, 44, "Green"s);     // this snaps to the grid
    cout << cp << endl;

    cp.ChangeColor("Blue"s);
    cout << cp << endl;

    // p.SnapToGrid();          // can't access protected method here
    // c.SnapToGrid();          // can't access protected method here
}
