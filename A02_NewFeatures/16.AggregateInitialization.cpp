/*  Aggregate classes can be initialized from a braced initializer list.  To be an aggregate class
 *      1. all data members are public
 *      2. there are no constructors
 *      3. there are no in-class initializers
 *      4. there are no base classes or virtual functions
 * 
 *  The brace initialization is often used in the return stement of a function.
 *  Non aggregate classes can be brace initialized with {} using the default CTOR   
 */

#include <iostream>
using namespace std;

struct Point3       // aggregate class
{
    int x;
    int y;
    int z;
};

struct Point       // non aggregate class
{
    Point(): x(10),y(20) {}
    int x;
    int y;
};

// print functions
ostream& operator<<(ostream& out, const Point3& rhs)
{
    return out << rhs.x << "," << rhs.y << ","<< rhs.z;
}
ostream& operator<<(ostream& out, const Point& rhs)
{
    return out << rhs.x << "," << rhs.y;
}

// functions using brace initialization
Point f() 
{ 
    return {};   // default brace initialization (calls default CTOR) 
}
Point3 g() 
{ 
    return {}; // default brace initialization of aggregate class
}
Point3 h() 
{ 
    return {.x=1, .y=2, .z=3}; // brace initialization of aggregate class
}

/////

int main()
{
    cout << "brace initialization" << endl;
    Point p = f();
    cout << "p = " << p << endl;

    Point3 q = g();
    cout << "q = " << q << endl;

    Point3 r = h();
    cout << "r = " << r << endl;

    cout << ".z = " << h().z << endl; // just the z component
}
