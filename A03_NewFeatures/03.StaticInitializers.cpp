// instance variable can be initialized in class definition,
// static variables can be initialized in class definition if declared inline (since C++17)

#include <iostream>
using namespace std;

class Point
{
public:
	Point() {}  // required, but x and y initialized to 5 and 7 elsewhere
	void incrementCounts()
	{
		Point::count1++;
		Point::count2++;
	}
	friend ostream& operator<<(ostream& os, Point p)
	{
		return os << p.x << ":" << p.y << "(" << count1 << "," << count2 << ")";
	}
protected:
	inline static int count1 = 10;  // inline required if static declared inside class
	static int count2;              // no inline keyword => requires a declaration outside the class
private:
	int x = 5;
	int y = 7;
};
int Point::count2 = 20; // linker error if this line is not present

int main()
{
	Point p{};   // calls default CTOR
	cout << "p=" << p << endl;
	p.incrementCounts();
	cout << "p=" << p << endl;
}

