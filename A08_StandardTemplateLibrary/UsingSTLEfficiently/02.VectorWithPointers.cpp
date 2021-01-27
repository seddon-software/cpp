#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point
{
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
private:
	int x;
	int y;
};

void pushObjects()
{
	cout << "\nusing objects" << endl;
	cout << "=============" << endl;
	vector<Point> v;
	v.push_back(Point(2,1));
	v.push_back(Point(3,2));
	v.push_back(Point(5,3));
	v.push_back(Point(7,4));
	v.push_back(Point(11,5));
	v.push_back(Point(13,6));
}

void pushPointers()
{
	cout << "\nusing pointers" << endl;
	cout << "==============" << endl;
	vector<Point*> v;
	v.push_back(new Point(2,1));
	v.push_back(new Point(3,2));
	v.push_back(new Point(5,3));
	v.push_back(new Point(7,4));
	v.push_back(new Point(11,5));
	v.push_back(new Point(13,6));

	// clean up memory
	for(auto p : v)
	{
		delete p;
	}
}

int main()
{
	pushObjects();
	pushPointers();
}

