///////////////////////////////////////////////////////////////
//
//		Private Constructors
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <stdexcept>
using namespace std;

/*
 *  The factory method is a very important software pattern whereby we control how objects are created.
 *  In this example, we make the Point class constructor private; the only way to create Point objects
 *  is to use the static method: Create.
 * 
 *  Beacuse Create is a method of the class, it can access the private constructor and hence can create 
 *  Point objects (on the heap).  By making this the only way of creating Point objects we can easily 
 *  impose conditions on their creation.  Here, we choose to limit the number of Point objects to 3.
 * 
 *  We should clean up the heap at the end of he program; it would be better to use unique_ptrs to save
 *  having to do this.
 */ 

class Point
{
public:
    // factory method
    static Point* Create(int x, int y)
    {
        if(count == 3) 
            throw runtime_error("No more objects allowed"); 
        count++;
        return new Point(x, y);
    }

private:
    Point(int x, int y): x(x), y(y) {}    // private CTOR
    int x;
    int y;
    inline static int count = 0;
};

//int Point::count = 0;   // class static data


int main()
{
    Point* p1{0};
    Point* p2{0};
    Point* p3{0};
    Point* p4{0};

    try
    {
        p1 = Point::Create(10, 11);
        p2 = Point::Create(20, 21);
        p3 = Point::Create(30, 31);
        p4 = Point::Create(40, 41);
    }
    catch(const runtime_error& e)
    {
        cout << e.what() << endl;
    }
    if(p1) delete p1;
    if(p2) delete p2;
    if(p3) delete p3;
    if(p4) delete p4;
}

