////////////////////////////////////////////////////////////
//
//      Dynamic objects: new and delete
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
    int x;
    int y;
};

int main()
{
    Point* ptr;

    // do something
    ptr = new Point(10, 10);
    // do something

    delete ptr;
}
