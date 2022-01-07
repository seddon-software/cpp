#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
using namespace std;

/*  
 *  unique_ptrs are frequently used with our own classes to manage heap based objects.  Recall that if
 *  an exception is thrown all stack based objects are automatically destroyed (by the compiler), but
 *  heap based object are not.  Unless, of course, they are protected by a smart pointer. 
 *
 *  This example illustrates some of the unique_ptr methods and shows how to pass and return temporary 
 *  (r-val-references) objects to and from a function.
 */

class Point
{
public:
	Point(int x, int y) :x(x), y(y)
	{
		cout << "CTOR: " << *this << endl;
	}
	Point(const Point& old) :x(old.x), y(old.y)
	{
		cout << "copy CTOR" << endl;
	}
	~Point()
	{
		cout << "DTOR: " << *this << endl;
	}
	void hello()
	{
		cout << "Hello from " << *this << endl;
	}
friend ostream& operator<<(ostream& os, const Point& t);
private:
	int x;
	int y;
};
ostream& operator<<(ostream& os, const Point& t)
{
	os << "[" << t.x << "," << t.y << "]";
	return os;
}

unique_ptr<Point>&& rValueRefs(unique_ptr<Point>&& p)  // pass in a temporary
{
    p->hello();   // call a method
    return std::move(p);   // return a temporary
}

int main()
{
	// example Point objects
	unique_ptr<Point> p1(new Point(1,2));
	unique_ptr<Point> p2(new Point(3,4));
		cout << "*p1=" << *p1 << endl;
		cout << "*p2=" << *p2 << endl;
	// swap ownership
	p1.swap(p2);
		cout << "*p1=" << *p1 << endl;
		cout << "*p2=" << *p2 << endl;
	// transfers ownership from p2 to p1 and nullifies p2 
	p1 = std::move(p2);		
		cout << "*p1=" << *p1 << endl;
		cout << "p2=" << p2 << endl;
	// p2 takes on new ownership
	p2.reset(new Point(5,6));
		cout << "*p1=" << *p1 << endl;
		cout << "*p2=" << *p2 << endl;
	// pass and return r-value references to a function
	unique_ptr<Point> p3 = rValueRefs(std::move(p1));  // std::move creates a temporary
		cout << "p1=" << p1 << endl;
		cout << "*p3=" << *p3 << endl;
}	// DTORs called automatically

