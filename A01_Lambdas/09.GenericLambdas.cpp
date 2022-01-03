#include <iostream>
#include <string>
using namespace std;

// x is any type
auto treble = [](auto x){ return x + x + x; };

struct Point
{
    Point(int x, int y):x(x), y(y) {}
    int x;
    int y;
};

ostream& operator<<(ostream& os, const Point& p)
{
    os << "[" << p.x << "," << p.y << "]";
    return os;
}

Point operator+(const Point& lhs, const Point& rhs)
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

/////

int main()
{
    cout << treble(10) << endl;
    cout << treble(16.67) << endl;
    cout << treble(string("Hello ")) << endl;
    cout << treble(Point(3,5)) << endl;
}