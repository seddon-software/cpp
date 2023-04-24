/*
 *  All the STL container classes work with value semantics.  This means that when an item is added to a
 *  collection class the container takes a copy of the item and not a reference.
 * 
 *  To check this out we add some point objects to a vector and then modify the originals.  As you can
 *  verify by running this example, the vector's copies are unaffected by the modifications.
 */

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
    void doubleIt()
    {
        x *= 2;
        y *= 2;
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

    cout << endl << "original Points" << endl;
    p1.display();
    p2.display();
    p3.display();

    cout << endl << "Points in vector" << endl;
    for(auto& p: v)
    {
        p.display();
    }

    cout << endl << "modify all the points" << endl;
    p1.doubleIt();
    p2.doubleIt();
    p3.doubleIt();

    cout << "Points in vector (unchanged)" << endl;
    for(auto& p: v)
    {
        p.display();
    }

    cout << endl << "original Points (doubled)" << endl;
    p1.display();
    p2.display();
    p3.display();
}
