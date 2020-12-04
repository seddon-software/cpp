////////////////////////////////////////////////////////////
//
//      Dynamic arrays: new[] and delete[]
//
////////////////////////////////////////////////////////////

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
    [[ maybe_unused ]] int x;
    [[ maybe_unused ]] int y;
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

    // do something

    delete [] ptr;
}
