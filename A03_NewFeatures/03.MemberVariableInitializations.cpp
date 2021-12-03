// instance variable can be initialized in class definition,
// static variables can be initialized in class definition if declared inline (since C++17)

#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x = 0, int y = 0) : x(x), y(y)
	{
		Point::count++;
	}
	friend ostream& operator<<(ostream& os, Point p)
	{
		return os << p.x << ":" << p.y << "(" << count << ")";
	}
protected:
	inline static int count = 10;
private:
	int x = 0;
	int y = 0;
};

class NewPoint : public Point
{
public:
    NewPoint() {}
	NewPoint(int x, int y) : x(x), y(y) {}
private:
	// no need for default CTOR
	int x = 0;
	int y = 0;
};

int main()
{
	Point p1;
	cout << "p1=" << p1 << endl;
	Point p2(5,8);
	cout << "p2=" << p2 << endl;
	
	NewPoint p3{};		// calls the default CTOR
	cout << "p3=" << p3 << endl;
	NewPoint p4(5,8);
	cout << "p4=" << p4 << endl;
}

