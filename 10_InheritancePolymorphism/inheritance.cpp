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

class ColoredPoint: public Point
{
public:
	ColoredPoint(int x0, int y0, int color) : Point(x0, y0), color(color) {}
	void print()
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
	cout << p.print() << endl;
	cp.print();
}
