/*
 *  The format library is a typesafe printing library along the lines of printf.  Format specifiers are
 *  essentially the same as printf.
 * 
 *  The library also allows you to output to a memory location (e.g. buffer) using:
 *              format_to
 */

#include <chrono>
#include <iostream>
#include <format>

using namespace std;
namespace C = std::chrono;

struct Point
{
    int x;
    int y;
};

ostream& operator<<(ostream& os, const Point& rhs)
{
    os << "p[x,y] = " << rhs.x << ":" << rhs.y << "\n";
    return os;
}

int main()
{
    int x = 100;
    Point p{3, 45};
    string buffer;

    cout << format("x = {0:}, {0:#x}\n", x);
    cout << format("π = {0:.3f}, e = {1:.6f}\n", 3.141592654, 2.7182818284);
    C::year_month_day birthday{C::year(2024)/C::month(1)/C::day(11)};
    cout << format("My next birthday is {}\n", birthday);
    cout << p << endl;
 
    cout << format("<{:6}>\n", x);
    cout << format("{:*<6}\n", x);
    cout << format("{:*>6}\n", x);

    // equivalent of sprintf (print to variable rather than stdout)
    std::format_to(
        std::back_inserter(buffer), // Output Iterator
        "My next birthday is {}\n", birthday);
    cout << buffer;
}
