/*
 *  Some attributes are shared by all objects in the class.  For example, when keeping count of the number of objects
 *  created for a class, it would not be appropriate to store this information in any given object.  Such attribute are called class
 *  attributes or static attributes on account of where in memory the infomation is stored (in the static section of the process).
 * 
 *  Methods interacting with static attributes are called static methods.  These methods are similar to regular methods, except they
 *  do not have a 'this' pointer (since there is no underlying object for 'this' to point at).  Both static attributes and methods
 *  are always prepended with the 'static' keyword.
 */

#include <iostream>
#include <string>
using namespace std;

class Point
{
public:

	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
	// CTOR
	Point(const string& name, int x0, int y0): name(name), x(x0), y(y0)
	{
		count++;
	}
	~Point()
	{
		count--;
		cout << "DTOR called" << this << endl;
	}
	void display()
	{
		cout << name << ": " << x << ", " << y << endl;
	}
	static int getCount() { return count; }
private:
	static int count;		// class attribute
	string name;
	int x;
	int y;
};
int Point::count = 0;

int main()
{
	// create 3 objects
	Point p1("point-p1", 100, 200);
	Point p2("point-p2", 110, 300);
	Point p3("point-p3", 150, 700);
	cout << Point::getCount() << endl;
	p1.moveBy(1, 1);
	p2.moveBy(10, 100);
	p3.moveBy(1, -1);
	p1.display();
	p2.display();
	p3.display();
}
