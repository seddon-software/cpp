#include <numeric>
#include <vector>
#include <iostream>
using namespace std;


// use accumulate algorithm from numerics library
// accumulate performs a left fold


struct Point
{
	Point(double x, double y) : x(x), y(y) {}
	Point operator+(const Point& rhs)
	{
		return Point(x+rhs.x, y+rhs.y);
	}
	double x;
	double y;
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << p.x << "," << p.y << endl;
	return os;
}

int main()
{
	vector<Point> points;
	points.push_back({5,6});
	points.push_back({7,2});
	points.push_back({3,5});
	points.push_back({4,6});
	points.push_back({8,6});

	Point total = accumulate(points.begin(), points.end(), Point(0, 0));
	cout << "Total: " << total << endl;
}
