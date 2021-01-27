#include <iostream>
#include <sstream>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

class Triangle
{
	friend ostream& operator<<(ostream& os, const Triangle& p);
public:
	Triangle()
	{
		cout << "CTOR()" << endl;
	}

	Triangle(int x, int y) : x(x), y(y)
	{
		cout << "CTOR(i,i)" << endl;
	}

	Triangle(Triangle&& temp ) noexcept : x(temp.x), y(temp.y)
	{
		std::cout << "Move" << std::endl;
	}

	Triangle( const Triangle& rhs ) : x(rhs.x), y(rhs.y)
	{
		std::cout << "Copy" << std::endl;
	}

	~Triangle()
	{
		cout << "DTOR" << endl;
	}

	Triangle& operator=(const Triangle& rhs)
	{
		std::cout << "=(&)" << std::endl;
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	Triangle& operator=(Triangle&& rhs)
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

ostream& operator<<(ostream& os, const Triangle& p)
{
	return os << p.x << "," << p.y;
}

int main()
{
	std::vector<unique_ptr<Triangle>> v;
	v.push_back(std::unique_ptr<Triangle>(new Triangle(3, 4)));
	v.push_back(std::unique_ptr<Triangle>(new Triangle(5, 3)));
	v.push_back(std::unique_ptr<Triangle>(new Triangle(7, 2)));

	for (auto i = v.begin(); i != v.end(); ++i)
	{
		unique_ptr<Triangle>& p = *i;
		p->moveBy(1, 1);
		cout << p->details() << endl;
	}

	// check vector has been updated
	for (auto& ptr : v)
	{
		cout << ptr->details() << endl;
	}
}
