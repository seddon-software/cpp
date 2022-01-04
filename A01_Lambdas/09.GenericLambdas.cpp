#include <iostream>
#include <string>
using namespace std;

/*  Generic lambdas were introduced in C++14.  By using auto as the closure type defined by the lambda 
 *  expression the lambda will be converted to a template automatically by the compiler.
 *  This example uses an int, double, string and user defined class with the rsulting template.
 */

// Generic lambda (x is any type)
auto treble = [](auto x){ return x + x + x; };

struct Point
{
    Point(int x, int y): x(x), y(y) {}

    friend ostream& operator<<(ostream& os, const Point& p)
    {
        os << "[" << p.x << "," << p.y << "]";
        return os;
    }
    Point operator+(const Point& rhs) const
    {
        return Point(x + rhs.x, y + rhs.y);
    }

    int x;
    int y;
};



/////

int main()
{
    cout << treble(10) << endl;
    cout << treble(16.67) << endl;
    cout << treble(string("Hello ")) << endl;
    cout << treble(Point(3,5)) << endl;       // vscode incorrectly thinks this is an error
}