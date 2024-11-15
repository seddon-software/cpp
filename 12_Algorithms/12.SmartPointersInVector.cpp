/*
 *  You can store unique_ptrs in a vector, but because the vector uses value semantics it will try to
 *  copy the unique_ptrs (which is not allowed).  You can get round this by using std::move to make the
 *  unique_ptrs r-value references.
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Point
{
public:
    Point(int x, int y):x(x), y(y)
    {
        cout << "CTOR called on: " << x << ", " << y << endl;
    }
    ~Point() 
    {
        cout << "DTOR called on: " << x << ", " << y << endl;
    }
private:
    int x, y;
};

// unique pointers maintain ownership
// and clean up on exit from a function because they are stack based


int main()
{
    unique_ptr<Point> u1{new Point{30,40}};
    unique_ptr<Point> u2{new Point{70,80}};
    unique_ptr<Point> u3{new Point{30,90}};
    vector<unique_ptr<Point>> v;
    // note you can't copy a unique_ptr, but you can move them
    v.push_back(std::move(u1));
    v.push_back(std::move(u2));
    v.push_back(std::move(u3));
}
