#include <iostream>
#include <string>
using namespace std;

class Triangle
{
public:

	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
	// CTOR
	Triangle(const string& name, int x0, int y0): name(name), x(x0), y(y0)
	{
		count++;
	}
	~Triangle()
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
int Triangle::count = 0;

int main()
{
	// create 3 objects
	Triangle p1("point-p1", 100, 200);
	Triangle p2("point-p2", 110, 300);
	Triangle p3("point-p3", 150, 700);
	cout << Triangle::getCount() << endl;
	p1.moveBy(1, 1);
	p2.moveBy(10, 100);
	p3.moveBy(1, -1);
	p1.display();
	p2.display();
	p3.display();
}
