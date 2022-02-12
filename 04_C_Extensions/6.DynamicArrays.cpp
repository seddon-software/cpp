////////////////////////////////////////////////////////////
//
//      Dynamic arrays: new[] and delete[]
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*  
 *  In addition to the new and delete operators, C++ provides new[] and delete[] to manage arrays on the heap.
 *  Nowadays, we tend to use vectors instead of raw arrays, but these two operators are still available; 
 *  actually, vector uses the heap behind the scenes.
 * 
 *  Nevertheless, in this example we show how to use these raw operators.  Normally, we create default 
 *  constructed objects on the heap as in:
 *             ptr = new Point[3];
 *  but we can invoke other constructors as in:
 *             ptr = new Point[3] {{10,20},{10,20},{10,20}};
 *
 *  Note that because we are dealing with arrays, new will first allocate memory and then call constructors
 *  for each item in the array.  Similarly, on destruction, destructors are called for each item in the array. 
 */

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

    Point(int x0, int y0)
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

private:
    int x;
    int y;
};

//////

int main()
{
    Point* ptr;

    // do something

    ptr = new Point[3];

    ptr[0] = Point(10, 10);
    ptr[1] = Point(20, 20);
    ptr[2] = Point(30, 30);

    // ... now use the array ...

    delete [] ptr;  // cleanup

    // invoke different CTOR(int, int) for each item in array
    ptr = new Point[3] {{10,20},{10,20},{10,20}};
    delete [] ptr;  // cleanup
}
