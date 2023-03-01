////////////////////////////////////////////////////////////
//
//      Aggregation
//
////////////////////////////////////////////////////////////

/*
 * Aggregation is where an object is made up of other child objects.
 * Unlike Composition, the child object can exist independently of the parent.
 */

#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x0=0, int y0=0):x(x0), y(y0) {}
	Point(const Point& original) : x(original.x), y(original.y) {}
	void display() { 
		cout << "x,y=" << x << "," << y;
		cout.flush();
	}
private:
	int x;
	int y;
};

class Polygon
{
public:
	Polygon(int x0, int y0, int x1, int y1): topLeft(x0, y0), bottomRight(x1, y1) {}
	Polygon(const Point& p1, const Point& p2) : topLeft(p1), bottomRight(p2) {}
	void display()
	{
		topLeft.display();
		cout << endl;
		bottomRight.display();
		cout << endl;
	}
private:
	Point topLeft;
	Point bottomRight;
};

int main()
{
	Polygon r(10, 20, 100, 110);
	Point tl(10, 20);
	Point br(100, 110);
	Polygon(tl, br);
	r.display();
}






