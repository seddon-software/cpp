#include <iostream>
#include <vector>
#include <memory>
using namespace std;


/*  
 *  REWORD
 *  As an alternative to unique_ptr, we can used shared_ptr.  The shared_ptr also uses the handle-body 
 *  paradigm, but in this case the handles use reference counting.  When the last reference expires, the
 *  body is deleted.  This makes managed heap based objects exception safe in the same way as with 
 *  unique_ptrs. 
 * 
 *  However, it is now same to pass these smart pointers by copy as this merely increments the reference 
 *  count.
 */

class Point
{
	friend ostream& operator<<(ostream& os, const shared_ptr<Point>& p)
	{
		return os << "[" << p->x << "," << p->y << "]";
	}
public:
	Point(int x, int y) : x(x), y(y) {}
	~Point() { cout << "DTOR" << endl; }
	void moveBy(int dx, int dy)
	{
		x += dx;
		y += dy;
	}
private:
	int x;
	int y;
};

// this is really a template
void f(auto p)
{
	cout << "There are " << p.use_count() << " references to this shared pointer" << endl;
	p->moveBy(1, 1);
}

void g(auto& p)
{
	cout << "There are " << p.use_count() << " references to this shared pointer" << endl;
	p->moveBy(1, 1);
}

int main()
{
	shared_ptr<Point> p1(new Point(3, 4));
	shared_ptr<Point> p2(new Point(5, 3));
	shared_ptr<Point> p3(new Point(7, 2));

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;	

	// pass by reference
	g(p1);
	g(p2);
	g(p3);

	// check points have been updated
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;	

	// pass by value
	f(p1);
	f(p2);
	f(p3);

	// check points have been updated
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;	
} // DTOR called automatically
