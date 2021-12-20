#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Point
{
public:
    Point(int x, int y):x(x), y(y) {}
    ~Point() 
    {
        cout << "DTOR called on: " << x << ", " << y << endl;
    }
private:
    int x, y;
};

// unique pointers maintain ownership
// and clean up on exit from a function because they are stack based
void f1()
{
    [[maybe_unused]]
    Point* p1 = new Point{3,4};     // no DTOR called on exit from function
    unique_ptr<Point> u1{new Point{30,40}};
}

void f2()
{
    [[maybe_unused]]
    Point* p2 = new Point{7,8};     // no DTOR called on exit from function
    unique_ptr<Point> u2{new Point{70,80}};
}

void f3()
{
    [[maybe_unused]]
    Point* p3 = new Point{3,9};     // no DTOR called on exit from function
    unique_ptr<Point> u3{new Point{30,90}};
}

int main()
{
    f1();
    f2();
    f3();
}
