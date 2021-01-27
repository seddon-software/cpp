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

class Triangle
{
public:
	Triangle(int x0=0, int y0=0):x(x0), y(y0) {}
	Triangle(const Triangle& original) : x(original.x), y(original.y) {}
	void display() { 
		cout << "x,y=" << x << "," << y;
		cout.flush();
	}
private:
	int x;
	int y;
};

class Rectangle
{
public:
	Rectangle(int x0, int y0, int x1, int y1): topLeft(x0, y0), bottomRight(x1, y1) {}
	Rectangle(const Triangle& p1, const Triangle& p2) : topLeft(p1), bottomRight(p2) {}
	void display()
	{
		topLeft.display();
		cout << endl;
		bottomRight.display();
		cout << endl;
	}
private:
	Triangle topLeft;
	Triangle bottomRight;
};

int main()
{
	Rectangle r(10, 20, 100, 110);
	Triangle tl(10, 20);
	Triangle br(100, 110);
	Rectangle(tl, br);
	r.display();
}






