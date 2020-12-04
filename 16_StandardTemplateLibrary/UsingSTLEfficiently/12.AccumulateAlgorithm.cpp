#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

struct Point
{
	Point(double x, double y) : x(x), y(y) {}
	double x;
	double y;
};

class PointAverage
{
public:
	PointAverage() : count(0), xTotal(0), yTotal(0) {}
	const Point operator()(const Point& runningAverage, const Point& next)
	{
		count++;
		xTotal += next.x;
		yTotal += next.y;
		return Point(xTotal/count, yTotal/count);
	}
private:
	int count;
	double xTotal;
	double yTotal;
};

int main()
{
	vector<Point> points;
	points.push_back({5,6});
	points.push_back({7,2});
	points.push_back({3,5});
	points.push_back({4,6});
	points.push_back({8,6});

	Point average = accumulate(points.begin(), points.end(), Point(0, 0), PointAverage());
	cout << average.x << "," << average.y << endl;
}
