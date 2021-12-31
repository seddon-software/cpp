////////////////////////////////////////////////////////////
//
//		Undo
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


class Point
{
public:
    Point(double x0 = 0, double y0 = 0) 
        : x(x0), y(y0), distance(0) {}
    void MoveBy(double dx, double dy);
    void Print();
    void Undo();
private:
    static double Distance(Point p1, Point p2);
    double x;
    double y;
    double distance;
    vector<Point> history;
};

double Point::Distance(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void Point::MoveBy(double dx, double dy)
{
    history.push_back(*this);

    Point original(*this);
    x += dx;
    y += dy;
    distance += Distance(*this, original);
}

void Point::Undo()
{
    Point p = history.back();
    // copy p to *this, but don't overwrite history
    x = p.x;
    y = p.y;
    distance = p.distance;
    history.pop_back();
}

void Point::Print()
{
    cout << "x=" << x 
         << ",y=" << y 
         << ",distance=" << distance << endl;
}

/////

int main()
{
    Point p(27, 31); p.Print();
    p.MoveBy(10, 20); p.Print();
    p.MoveBy(10, 20); p.Print();
    p.MoveBy(10, 20); p.Print();
    p.Undo(); p.Print();
    p.MoveBy(10, 20); p.Print();
    p.Undo(); p.Print();
    p.Undo(); p.Print();
    p.Undo(); p.Print();
}
