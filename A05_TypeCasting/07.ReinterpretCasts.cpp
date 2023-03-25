#include <iostream>
using namespace std;

/*
 *  In this example we use reinterpret_cast with non polymorhic types.  These cast often produce errors.
 *  Our Time object is converted to an integer and because they are different sizes in memory, the compiler
 *  reads the wrong memory into the int.  Similarly, a Time and Point object have nothing in common, so
 *  does it really make sense to perform the cast.  Yhis time, the two objects have the same memory 
 *  footprint, so we don't get a strange result.  Nevertheless, the cast is highly dubious.
 */

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
	cout << i << endl;
	p = *reinterpret_cast<Point*>(&i);	// another dubious cast
	cout << p << endl;
}

