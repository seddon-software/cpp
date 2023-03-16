#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
    void display()
    {
        cout << this << ": " << x << "," << y << endl;
    }
};

int main()
{
    Point p1{3,4};
    Point p2{7,8};
    Point p3{3,9};

    vector<Point> v;
    v.push_back(p1);    // pushes a copy of p1
    v.push_back(p2);
    v.push_back(p3);

    cout << "Points in vector" << endl;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        i->display();
    }
    cout << "references to Points in vector" << endl;
    for(auto& x : v) // C++11 new loop syntax
    {
        x.display();
    }
    cout << "copies of Points in vector" << endl;
    for(auto x : v) // C++11 new loop syntax
    {
        x.display();
    }
    cout << "original Points" << endl;
    p1.display();
    p2.display();
    p3.display();
}
