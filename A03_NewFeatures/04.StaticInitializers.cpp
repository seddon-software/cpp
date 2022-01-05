#include <iostream>
using namespace std;

/*  
 *  Although we can now initialize instance variables in the class definition (since C++11), static 
 *  variables were exempt.  However C++17 now allows statics to be initialized in class definition
  * provided they are declared as inline.  By declaring the static inline, the compiler will also
  * allocate static storage, obviating the need to declare and initialize the static outside the 
  * class, as was previously required.
  */

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
		return os << "p.x = " << p.x << ", " 
                  << "p.y = " << p.y << ", "
                  << "Point::.count1 = " << Point::count1 << ", "
                  << "Point::.count2 = " << Point::count2 << endl;
	}
protected:
	inline static int count1 = 10;  // inline required if static declared inside class
	static int count2;              // no inline keyword => requires a declaration outside the class
private:
	int x = 5;
	int y = 7;
};

// statics had to be declared and initialized outside the class prior to C++17 and still have 
// to be if not declared inline
int Point::count2 = 20; // count2 not declared inline; linker error if this line is not present

int main()
{
	Point p{};   // calls default CTOR
	cout << p;
	p.incrementCounts();
	cout << p;
}

