#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Point
{
friend ostream& operator<<(ostream& os, const Point& p);
public:
	Point(int x, int y) : x(x), y(y)
	{
		cout << "CTOR called" << endl;
	}
	Point(const Point& p) : x(p.x), y(p.y)
	{
		cout << "Copy CTOR called" << endl;
	}
	~Point()
	{
		cout << "DTOR called" << endl;
	}
	bool operator<(const Point& rhs)
	{
		return x < rhs.x;
	}
private:
	int x;
	int y;
};


ostream& operator<<(ostream& os, const Point& p)
{
	os << " [" << p.x << "," << p.y << "] ";
	return os;
}

int main()
{
	vector<Point*> v;
	v.reserve(6);
	v.push_back(new Point(11,5));
	v.push_back(new Point(5,3));
	v.push_back(new Point(2,1));
	v.push_back(new Point(7,4));
	v.push_back(new Point(13,6));
	v.push_back(new Point(3,2));

	sort(v.begin(),
		 v.end(),
		 [](Point* lhs, Point* rhs) { return *lhs < *rhs; });

	for(auto i : v)
	{
		cout << *i << endl;
	}

	// clean up memory
	for(unsigned i = 0; i < v.size(); i++)
	{
		delete v[i];
	}
}

