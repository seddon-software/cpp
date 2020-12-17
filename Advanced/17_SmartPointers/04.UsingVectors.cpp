#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

class Point
{
	friend ostream& operator<<(ostream& os, const Point& p);
public:
	Point()
	{
		cout << "CTOR()" << endl;
	}

	Point(int x, int y) : x(x), y(y)
	{
		cout << "CTOR(i,i)" << endl;
	}

	Point(Point&& temp ) noexcept : x(temp.x), y(temp.y)
	{
		std::cout << "Move" << std::endl;
	}

	Point( const Point& rhs ) : x(rhs.x), y(rhs.y)
	{
		std::cout << "Copy" << std::endl;
	}

	~Point()
	{
		cout << "DTOR" << endl;
	}

	Point& operator=(const Point& rhs)
	{
		std::cout << "=(&)" << std::endl;
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	Point& operator=(Point&& rhs)
	{
		std::cout << "=(&&)" << std::endl;
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

	string details() const
	{
		stringstream result(stringstream::in | stringstream::out);
		result << "[" << x << "," << y << "]";
		return result.str();
	}

private:
	int x;
	int y;
};

ostream& operator<<(ostream& os, const Point& p)
{
	return os << p.x << "," << p.y;
}

int main()
{
	std::vector<unique_ptr<Point>> v;
	v.push_back(std::unique_ptr<Point>(new Point(3, 4)));
	v.push_back(std::unique_ptr<Point>(new Point(5, 3)));
	v.push_back(std::unique_ptr<Point>(new Point(7, 2)));

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		unique_ptr<Point>& p = *i;
		p->moveBy(1, 1);
		cout << p->details() << endl;
	}

	// check vector has been updated
	for (auto& ptr : v)
	{
		cout << ptr->details() << endl;
	}
}
