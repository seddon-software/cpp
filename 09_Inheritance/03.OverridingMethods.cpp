#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Triangle
{
public:
	Triangle(int x0, int y0):x(x0), y(y0) {}
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
class ColoredPoint: public Triangle
{
public:
	ColoredPoint(int x0, int y0, int color) : Triangle(x0, y0), color(color) {}
	// note: return type doesn't have to be the same as in the base class
	void print()
	{
		cout << Triangle::print() << " color= " << color << endl;
	}
private:
	int color;
};

int main()
{
	Triangle p(5, 8);
	ColoredPoint cp(10, 20, 25);
	cout << p.print() << endl;
	cp.print();
}
