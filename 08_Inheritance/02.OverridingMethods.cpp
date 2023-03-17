/*
 * In this example we see how to add a print function to a derived class which prints out all
 * the attributes of the class including the attributes defined in the base class.  The problem with
 * this is that the derived class doesn't have direct access to the base class attributes because they 
 * are declared as private.
 * 
 * We need to arrange for the base class to return a string containg information about the base class 
 * attributes and then append information about the derived class attributes.  The best way to do this
 * is to use a strstring object to build the base class string.
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Point
{
public:
	Point(int x0, int y0):x(x0), y(y0) {}
	string print()
	{
		stringstream s;
		s << "x = " << x << ", y = " << y;
		return s.str();
	}
private:
	int x;
	int y;
};

// derived classes can override methods (print)
class ColoredPoint: public Point
{
public:
	ColoredPoint(int x0, int y0, const string& color) : Point(x0, y0), color(color) {}
	// note: return type doesn't have to be the same as in the base class
	string print()
	{
		stringstream s;
		s << Point::print() << ", color:" << color << endl;
		return s.str();
	}

private:
	string color;
};

int main()
{
	Point p(5, 8);
	ColoredPoint cp(10, 20, "Blue"s);
	cout << cp.print() << endl;
}
