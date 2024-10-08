/*  
 *  In addition to the new and delete operators, C++ provides new[] and delete[] to manage arrays on the heap.
 *  Nowadays, we tend to use vectors instead of raw arrays, but these two operators are still available.
 * 
 *  In this example we show how to use these raw operators.  Normally, we create default constructed objects 
 *  on the heap as in:
 *             ptr = new Point[3];
 * 
 *  but we can invoke other constructors as in:
 *             ptr = new Point[3] {{10,20},{10,20},{10,20}};
 *
 *  Note that because we are dealing with arrays, 'new []' will first allocate memory and then call constructors
 *  for each item in the array.  Similarly, on destruction, destructors are called for each item in the array. 
 * 
 *  It may be important to use delete[] to clean up the array on the heap.  If you omit the brackets and use
 *  'delete' to clean up, then only the first array item will have its destructor called.  This is not a 
 *  problem with built in types like int and double because they don't have constructors and destructors, but 
 *  it may result in memory leaks for user defined types.
 *
 *  Note that we need to overload the << operator to be able to print our objects: 
 *     friend ostream& operator<<(ostream& os, const Point& p)
 *  
 *  Operator overloading will be explained later in the course.
 */

#include <iostream>
using namespace std;

class Point
{
public:
    Point()        // default CTOR
    :
        x(0),
        y(0)
    {
        cout << "Default CTOR" << endl;
    }

    Point(int x0, int y0)   // CTOR(int, int)
    :
        x(x0),
        y(y0)
    {
        cout << "int int CTOR" << endl;
    }

    ~Point()
    {
        cout << "DTOR" << endl;
    }

    friend ostream& operator<<(ostream& os, const Point& p)
    {
        os << "[" << p.x << "," << p.y << "] ";
        return os;
    }
private:
    int x;
    int y;
};

//////

void useTheArray(Point* p)
{
    cout << p[0] << ", " << p[1] << ", "<< p[2] << endl;
}

int main()
{
    Point* ptr;

    ptr = new Point[3];

    ptr[0] = Point(10, 10);
    ptr[1] = Point(20, 20);
    ptr[2] = Point(30, 30);

    useTheArray(ptr);
    delete [] ptr;  // cleanup

    // invoke different CTOR(int, int) for each item in array
    ptr = new Point[3] {{10,20},{10,20},{10,20}};
    delete [] ptr;  // cleanup
}
