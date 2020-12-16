#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x0=0, int y0=0):x(x0), y(y0)
	{

	}
	Point(const Point& original) : x(original.x), y(original.y)
	{

	}
	void f1()
	{

	}
private:
	int x;
	int y;
};

class Rectangle
{
public:
	Rectangle(int x0, int y0, int x1, int y1): topLeft(x0, y0), bottomRight(x1, y1) {}
	Rectangle(const Point& p1, const Point& p2) : topLeft(p1), bottomRight(p2) {}
	void f()
	{
		topLeft.f1();
	}
private:
	Point topLeft;
	Point bottomRight;
};

int main()
{
	Rectangle r(10, 20, 100, 110);
	Point tl(10, 20);
	Point br(100, 110);
	Rectangle(tl, br);
	r.f();
}






