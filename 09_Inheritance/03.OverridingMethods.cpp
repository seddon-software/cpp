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
		s << x << ", " << y;
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
	ColoredPoint(int x0, int y0, int color) : Point(x0, y0), color(color) {}
	// note: return type doesn't have to be the same as in the base class
	string print()
	{
		stringstream s;
		s << Point::print() << ", color:" << color << endl;
		return s.str();
	}

	void print2()
	{
		cout << Point::print() << " color= " << color << endl;
	}
private:
	int color;
};

int main()
{
	Point p(5, 8);
	ColoredPoint cp(10, 20, 25);
	Point& ccp = cp;
	cout << ccp.print() << endl;
	cp.print();
}
