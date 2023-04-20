#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*  
 *  In this example we create a vector of unique_ptrs and subsequently pass this vector to a function.
 *  This illustrates how to extend the lifetime of objects managed by a unique_ptr.
 * 
 *  The key part of this example is to pass the vector by reference and not by value:
 *          void f(auto& v)
 * 
 *  When we pass by reference no copying is involved.  However. if we attempt to pass the vector by value 
 *  it will use value semantics to attempt to copy its contents to the copy.  This will result in a compiler
 *  error because you can't copy unique_ptr.
 */

class Point
{
	friend ostream& operator<<(ostream& os, const unique_ptr<Point>& p)
	{
		return os << "[" << p->x << "," << p->y << "]";
	}
public:
	Point(int x, int y) : x(x), y(y) {}

	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
private:
	int x;
	int y;
};

// this is really a template (because of auto)
void f(auto& v)     // must pass by reference not vale because of unique_ptr
{
	for (auto& ptr : v)
	{
		ptr->moveBy(1, 1);
		cout << ptr << endl;
	}
}

int main()
{
	vector<unique_ptr<Point>> v;
	v.push_back(std::unique_ptr<Point>(new Point(3, 4)));
	v.push_back(std::unique_ptr<Point>(new Point(5, 3)));
	v.push_back(std::unique_ptr<Point>(new Point(7, 2)));

	f(v);

	// check vector has been updated
	for (auto& ptr : v)
	{
		cout << ptr << endl;
	}
}
