////////////////////////////////////////////////////////////
//
//		Tuples
//
////////////////////////////////////////////////////////////

#include <iostream>
#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"
#include "boost/tuple/tuple_io.hpp"

using namespace std;
using namespace boost;

class Point
{
friend ostream& operator<<(ostream&, const Point&);
friend bool operator==(const Point&, const Point&);
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}
private:
	int x, y;
};

bool operator==(const Point& lhs, const Point& rhs)
{
	if (lhs.x != rhs.x) return false;
	if (lhs.y != rhs.y) return false;
	return true;
}

ostream& operator<<(ostream& out, const Point& p)
{
	out << "[" << p.x << "," << p.y << "]";
	return out;
}


void doit(int i, double d, const string& s, Point p)
{
	tuple<int, double, const string&, Point&> myTuple = make_tuple(i, d, cref(s), ref(p));
	cout << myTuple << endl;
}

int main()
{
	// creation
	tuple<int, double, string, Point> myTuple(1, 3.14, string("Hello"), Point(3,4));

	// printing
	cout << myTuple << endl;

	// make_tuple
	doit(2, 1.72, "Goodbye", Point(10,50));

	// extraction
	int i = myTuple.get<0>(); 		cout << i << endl;
	double d = myTuple.get<1>(); 	cout << d << endl;
	string s = myTuple.get<2>(); 	cout << s << endl;
	Point p = myTuple.get<3>(); 	cout << p << endl;

	// assignment
	tuple<int, double, string, Point> myTuple2;
	myTuple2 = myTuple;
	cout << myTuple2 << endl;

	// comparison
	if (myTuple2 == myTuple)
	{
		cout << "tuples are equal" << endl;
	}

	return 0;
}
