//////////////////////////////////////////////////////////////////////
//
//		Placement new
//
//////////////////////////////////////////////////////////////////////


#include <new>
#include <iostream>
using namespace std;


#if defined(WIN32)
#include <windows.h>
#else
#include <sys/mman.h>
#endif


template <typename T>
T* memoryAllocator(int n)
{
#if defined(WIN32)
	void* ptr =  VirtualAlloc(
    		0,
			n * sizeof(T),
			MEM_COMMIT,
			PAGE_READWRITE
			);
#else
	void* ptr = mmap(
			0, 	                    // void *addr,
			n * sizeof(T),          // size_t len,
			PROT_READ | PROT_WRITE, // int prot,
			MAP_SHARED | MAP_ANON,  // int flags,
			-1,                     // int fd (no file backing),
			0                       // off_t offset);
			);
#endif
    T* array = reinterpret_cast<T*>(ptr);
    return array;
}

class Date
{
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    ~Date() {}

    void display()
    {
        cout << "Date: " << day << "-" << month << "-" << year << endl;
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
    Point(int x0, int y0) : x(x0), y(y0) {}
    ~Point() {}

    void display()
    {
        cout << "Point is at: " << x << ", " << y << endl;
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
    Point* points = memoryAllocator<Point>(100); // space for 100 Point objects
    Date* dates = memoryAllocator<Date>(100); // space for 100 Date objects

    // place objects in memory pools
    new (&points[0]) Point(10, 20);
    new (&points[1]) Point(11, 21);
    new (&points[2]) Point(12, 22);
    new (&points[3]) Point(13, 23);

    new (&dates[0]) Date(12, 8, 2019);
    new (&dates[1]) Date(22, 5, 2020);
    new (&dates[2]) Date(31, 1, 2021);
    new (&dates[3]) Date(4, 11, 2018);

    // code to use shared memory objects ...
    for (int i = 0; i < 4; i++)
    {
        points[i].display();
        dates[i].display();
    }

    // call DTORs for each object
    // objects are not on the heap so delete must not be called
    for (int i = 0; i < 4; i++)
    {
        points[i].~Point();
        dates[i].~Date();
    }
}

