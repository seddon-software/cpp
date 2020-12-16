////////////////////////////////////////////////////////////
//
//		Reinterpret Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class Time
{
public:
	Time(int h = 0, int m = 0) : hrs(h), min(m) {}
private:
	short hrs;
	short min;
};

class Point
{
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
	ostream& operator<<(ostream& os) const
	{
		os << x << "," << y << endl;
		return os;
	}
private:
	short x;
	short y;
};

ostream& operator<<(ostream& os, const Point& p)
{
	return p << os;
}
//////

int main()
{
	Time t(5, 20);
	Point p;
	int i;
	// reinterpret_cast often is used as a kludge
	i = *reinterpret_cast<int*>(&t);	// dubious cast
	p = *reinterpret_cast<Point*>(&i);	// another dubious cast
	cout << p << endl;
}

