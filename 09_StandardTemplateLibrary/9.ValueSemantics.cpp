#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
    void update()
    {
        x *= 10;
        y *= 10;
    }
    void display()
    {
        cout << x << "," << y << endl;
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

    for(auto i = v.begin(); i != v.end(); ++i)
    {
    	i->update();
        i->display();
    }
    p1.display();
    p2.display();
    p3.display();
}
