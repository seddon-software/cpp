#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
using namespace std;

class Point
{
public:
	Point(int x, int y) :x(x), y(y)
	{
		cout << "CTOR" << endl;
	}
	Point(const Point& old) :x(old.x), y(old.y)
	{
		cout << "copy CTOR" << endl;
	}
	Point(Point&& temp) noexcept :x(temp.x), y(temp.y)
	{
		cout << "move CTOR" << endl;
	}
	~Point()
	{
		cout << "DTOR" << endl;
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

int main()
{
	{
		unique_ptr<int> p1;
		// *p1 = 23; // => generates runtime error

		unique_ptr<int> p2(new int(5));

		// private copy CTOR to prevent the following
		// unique_ptr<int> p2 = p1; // => generates compile error

		// to transfers ownership use explicit move
		p1 = move(p2);
		cout << *p1 << endl;
		p1.reset(); // deletes the memory
	}
	{
		unique_ptr<Point> p(new Point(3,4));
		cout << p->details() << endl;
	}	// DTOR called automatically
}

