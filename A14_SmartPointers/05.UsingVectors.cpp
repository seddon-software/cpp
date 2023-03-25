#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*  
 *  In this example we create a vector of unique_ptrs and subsequently pass this vector to a function.
 *  This illustrates how to extend the lifetime of objects managed by a unique_ptr.
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

// this is really a template
void f(auto& v)
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
