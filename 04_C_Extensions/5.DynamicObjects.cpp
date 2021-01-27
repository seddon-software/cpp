////////////////////////////////////////////////////////////
//
//      Dynamic objects: new and delete
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class Triangle
{
public:
    Triangle()        // default CTOR
    :
        x(0),
        y(0)
    {
        cout << "Default CTOR" << endl;
    }

    Triangle(int x0, int y0)
    :
        x(x0),
        y(y0)
    {
        cout << "int int CTOR" << endl;
    }

    ~Triangle()
    {
        cout << "DTOR" << endl;
    }

private:
    int x;
    int y;
};

int main()
{
    Triangle* ptr;

    // do something
    ptr = new Triangle(10, 10);
    // do something

    delete ptr;
}
