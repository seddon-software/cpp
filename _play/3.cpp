#include <iostream>
using namespace std;

class Point
{
private:
    int x;      // instance variable
    int y;
public:
    // CTOR
    Point(int x0, int y0) : x(x0), y(y0) {}   // initialization list
    // methods/operations/functions
    void moveBy(int dx, int dy);
    void display() const;
};

void Point::moveBy(int dx, int dy)
{
    x += dx;
    y += dy;
}
void Point::display() const
{
    cout << x << "," << y << endl;        
}

int main()
{    
    // create a Point object
    Point p(99, 44);        // local variable, stack based, not initialized
    p.moveBy(10, 20);
    p.display();
}
