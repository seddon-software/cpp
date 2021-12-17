#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
using namespace std;

class Triangle
{
public:
	Triangle(int x, int y) :x(x), y(y)
	{
		cout << "CTOR: " << *this << endl;
	}
	Triangle(const Triangle& old) :x(old.x), y(old.y)
	{
		cout << "copy CTOR" << endl;
	}
	Triangle(Triangle&& temp) noexcept :x(temp.x), y(temp.y)
	{
		cout << "move CTOR: " << *this << endl;
	}
	~Triangle()
	{
		cout << "DTOR: " << *this << endl;
	}
	string details() const
	{
		stringstream result(stringstream::in | stringstream::out);
		result << "[" << x << "," << y << "]";
		return result.str();
	}
friend ostream& operator<<(ostream& os, const Triangle& t);
private:
	int x;
	int y;
};
ostream& operator<<(ostream& os, const Triangle& t)
{
	os << "[" << t.x << "," << t.y << "]";
	return os;
}
int main()
{
	// set up a stack frame
	{
		// unique_ptr is an example of Handle Body, and the Body must be on the heap
		unique_ptr<int> p1;
		// *p1 = 23; // => generates runtime error (23 is not on the heap)

		unique_ptr<int> p2(new int(5));		// OK, 5 is on the heap

		// unique_ptr has private COPY CTOR to prevent copying
		// unique_ptr<int> p2 = p1; // => generates compile error

		// to transfers ownership use explicit move
		p1 = move(p2);
		cout << *p1 << endl;
		p1.reset(); // deletes the body before leaving the stack frame
	}
	{
		// works with user defined classes
		unique_ptr<Triangle> p1;
		unique_ptr<Triangle> p2(new Triangle(3,4));
		cout << *p2 << endl;
		p1 = move(p2);
		p1.reset();

		unique_ptr<Triangle> p3(new Triangle(8,11));
		cout << *p3 << endl;
	}	// DTOR called automatically
}

