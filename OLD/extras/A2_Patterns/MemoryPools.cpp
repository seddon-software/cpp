//////////////////////////////////////////////////////////////////////
//
//		Placement new
//
//////////////////////////////////////////////////////////////////////

#include <windows.h>
//#include <new>
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
	~Date() {}

	void Display()
	{
		cout << "Date: " << day << "-" << month << "-" << year << endl;
	}

	static Date* AllocateMemory()
	{
		Date* array = (Date*) VirtualAlloc(
							0, 
							100 * sizeof(Date), 
							MEM_COMMIT, 
							PAGE_READWRITE);
		return array;
	}

	static void* operator new(size_t, void* address)
	{
		return address;
	}

private:
	int day;
	int month;
	int year;
};

class Point
{
public:
	Point(int x0, int y0) : x(x0),y(y0) {}
	~Point() {}
	
	void WhereAreYou()
	{
		cout << "Point is at: " << x << ", " << y << endl;
	}

	static Point* AllocateMemory()
	{
		Point* array = (Point*) VirtualAlloc(
							0, 
							100 * sizeof(Point), 
							MEM_COMMIT, 
							PAGE_READWRITE);
		return array;
	}

	static void* operator new(size_t, void* address)
	{
		return address;
	}

private:
	int x;
	int y;
};

/////

int main()
{
	// pre-allocate raw memory for objects
	Point* points = Point::AllocateMemory();  // space for 100 objects
	Date*  dates  = Date ::AllocateMemory();  // space for 100 objects

	// place objects in raw memory

	new (&points[0]) Point(10, 20);
	new (&points[1]) Point(11, 21);
	new (&points[2]) Point(12, 22);
	new (&points[3]) Point(13, 23);

	new (&dates[0]) Date(12,  8, 1999);
	new (&dates[1]) Date(22,  5, 2000);
	new (&dates[2]) Date(31,  1, 2001);
	new (&dates[3]) Date( 4, 11, 1999);

	// code to use shared memory objects ...
	for(int i = 0; i < 4; i++)
	{
		points[i].WhereAreYou();
		dates[i].Display();
	}

	// call DTORs for each object
	// objects are not on the heap so delete must not be called
	for(int i = 0; i < 4; i++)
	{
		points[i].~Point();
		dates[i].~Date();
	}

	return 0;
}
  
