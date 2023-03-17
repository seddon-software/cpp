/*
 *  In this example we define a base class Point and two derived classes.  All derived classes support the
 *  ISA relationship:
 *          Snap ISA Point
 *          ColouredPoint ISA Point
 * 
 *  The Snap class needs to access its x and y attributes in order to snap to the grid.  Normally, these
 *  would be declared private in the base class, but in this case we must declare them protected to make
 *  them accessible in he derived class.
 * 
 *  The Snap class needs to override the MoveBy method in order to ensure its new position is on the grid.
 * 
 *  The ColordPoint class adds the methods:
 *          displayColor()
 *          changeColor()
 * 
 *  to support its additional attribute: color
 * 
 *  Note: the operator<< is declared as a friend of the base class and subsequently used by both of the 
 *  deived classes.
 */

#include <string>
#include <iostream>
using namespace std;

// this is the base class
class Point
{
public:
    Point(int x, int y): x(x), y(y) {}

    // this overload is invoked by derived classes and works because of the SUBSTUTION RULE (Point&).
    friend ostream& operator<<(ostream& out, const Point& p)
    {
        out << "Point: " << p.x << "," << p.y;
        return out;
    }
    void moveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
// make the attributes protected so that the derived class Snap can access x and y
protected:
    int x;
    int y;
};

class Snap : public Point
{
// the x and y coords must be a multiple of 10 to snap to a grid of spacing of 10 units
public:
    // the x and y attributes should be initialized by he base class
    Snap(int x=0, int y=0): Point(x-x%10, y-y%10) {}

    // we need to override the base class method in order to ensure snapping to grid
    void moveBy(int dx, int dy)
    {
        Point::moveBy(dx, dy);
        x -= x%10;
        y -= y%10;
    }
private:
    // no additional attributes
};

class ColoredPoint : public Point
{
public:
    ColoredPoint(int x, int y, const string& color): Point(x,y), color(color) {}
    void changeColor(const string& newColor)
    {
        color = newColor;
    }
    void displayColor() const
    {
        cout << "Color: " << color << endl;
    }
private:
    string color;
};

int main()
{
    Point p{53, 18};
    cout << p << endl;

    Snap snap{13, 27};
    cout << snap << endl;
    snap.moveBy(29, 17);
    cout << snap << endl;

    ColoredPoint colored{15, 18, "red"s};   // the s denotes string type, not const char*
    cout << colored << endl;
    colored.displayColor();
    colored.changeColor("blue"s);
    colored.displayColor();
}
