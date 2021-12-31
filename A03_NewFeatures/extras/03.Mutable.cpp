///////////////////////////////////////////////////////////////
//
//		Mutable
//
///////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Point
{
public:
	Point(int x0, int y0) : x(x0),y(y0), calls(0) {}

	void Print() const
	{
		cout << calls << ": Point is at "
			 << x << ", " << y << endl;
		calls++;
	}
private:
	int x;
	int y;
	mutable int calls;	// not part of logical object
};

/////

int main()
{
	const Point p(100, 200);

	p.Print();
	p.Print();
	p.Print();
	p.Print();

	return 0;
}
