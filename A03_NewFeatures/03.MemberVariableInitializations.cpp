// instance variable can be initialized in class definition,
// but static still must be allocated and initialized outside the class

#include <iostream>
using namespace std;

class Triangle
{
public:
	Triangle(int x = 0, int y = 0) : x(x), y(y)
	{
		count++;
	}
private:
	static int count;
	int x;
	int y;
};

int Triangle::count = 0;

class NewPoint
{
public:
	NewPoint()
	{
		count++;
	}
	NewPoint(int x, int y) : x(x), y(y)
	{
		count++;
	}
private:
	static int count;
	// no need for default CTOR
	int x = 0;
	int y = 0;
};

// still can't initialize static in class declaration
// C++ only allows static const integral types to be initialized in the class
int NewPoint::count = 0;

int main()
{
	Triangle p1;
	Triangle p2(5,8);
	NewPoint p3{};		// calls the default CTOR
	NewPoint p4(5,8);
}
