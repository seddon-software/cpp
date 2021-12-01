#include <iostream>
#include <vector>

using namespace std;

struct Triangle
{
    int x, y;
    void display()
    {
        cout << this << ": " << x << "," << y << endl;
    }
};

int main()
{
    Triangle p1{3,4};
    Triangle p2{7,8};
    Triangle p3{3,9};

    vector<Triangle> v;
    v.push_back(p1);    // pushes a copy of p1
    v.push_back(p2);
    v.push_back(p3);

    cout << "triangles in vector" << endl;
    for(auto i = v.begin(); i != v.end(); ++i)
    {
        i->display();
    }
    cout << "references to triangles in vector" << endl;
    for(auto& x : v) // C++11 new loop syntax
    {
        x.display();
    }
    cout << "copies of triangles in vector" << endl;
    for(auto x : v) // C++11 new loop syntax
    {
        x.display();
    }
    cout << "original triangles" << endl;
    p1.display();
    p2.display();
    p3.display();
}
