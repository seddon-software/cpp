#include <compare>
#include <iostream>
using namespace std;

/*  
 *  C++20 adds a new operator, affectionately dubbed the “spaceship” operator: <=>.  This operator
 *  was introduced to cut down on the boiler plate code, often present in classes, for comparisons.
 *  Its no longer necessary to define operator overloads for all 6 comparison operators:
 *      > >= < <= == !=
 *  However the semantics of comparison overloads has also changed.  3 different types of comparison
 *  are defined:
 *      strong ordering
 *      weak ordering
 *      partial ordering
 * 
 *  I'll only illustrate strong ordering (cppreference.com has full details of the others) as this 
 *  is the most common.  Furthermore you can define the spaceship operator, or the compiler can 
 *  autogenerate one for you.  In this example we'll define our own <=>.  As you will see we also 
 *  need to define the == operator.
 * 
 *  The operators <=> and == are now classified as primary operators.  You only need to define 
 *  these primary operators to get all 6 comparison operators, because of the compiler will
 *  rewrite the 6 comparison operators as below (Note that != is now defined in terms of ==): 
 *
 *      a < b       is rewritten    (a <=> b) < 0
 *      a <= b      is rewritten    (a <=> b) <= 0
 *      a > b       is rewritten    (a <=> b) > 0
 *      a >= b      is rewritten    (a <=> b) >= 0
 *      a == b      is rewritten    a == b
 *      a != b      is rewritten    !(a == b)
 * 
 * 
 *  In the example below we define an artificial class X and for the purposes of this example we regard
 *  the value of an X object as sum of the two instance variables a and b.  Next we define the two 
 *  primary overloads <=> and == for the class.  We do this for int and for const X& (4 obverloads 
 *  in total).
 *  
 *  A number of comparisions of X objects are considered in main() along with their rewritten 
 *  primary overloads.
 */

class X
{
private:
    int a;
    int b;
    // Note: for comparisons we consider the value of an object x of X to be x.a + x.b
public:
    explicit X(int a, int b): a(a), b(b) {}

    // define primary operators == and <=> for int and constX&
    bool operator==(int rhs) const                      // PRIMARY overload
    {
        cout << "== primary operator called" << endl;
        int lhs = a + b;
        return lhs == rhs;
    }
    bool operator==(const X& other) const               // PRIMARY overload
    {
        cout << "== primary operator called" << endl;
        int lhs = a + b;
        int rhs = other.a + other.b;
        return lhs == rhs;
    }
    strong_ordering operator<=>(int rhs) const          // PRIMARY overload
    {
        cout << "<=> primary operator called" << endl;
        int lhs = a + b;
        if(lhs == rhs)     return strong_ordering::equal;
        else if(lhs < rhs) return strong_ordering::less;
        else               return strong_ordering::greater;
    }
    strong_ordering operator<=>(const X& other) const   // PRIMARY overload
    {
        cout << "<=> primary operator called" << endl;
        int lhs = a + b;
        int rhs = other.a + other.b;
        if     (lhs == rhs) return strong_ordering::equal;
        else if(lhs < rhs)  return strong_ordering::less;
        else                return strong_ordering::greater;
    }
};

int main()
{
    // create 3 X objects
    X x(3, 5);
    X y(4, 7);
    X z(2, 6);

    // now for the comparisons
    if(x < y) cout << "x < y" << endl;      // (x <=> y) < 0
    if(x < 10) cout << "x < 10" << endl;    // (x <=> 10) < 0
    if(x >= 8) cout << "x >= 8" << endl;    // (x <=> 8) >= 0
    if(x > y) cout << "x > y" << endl;      // (x <=> y) > y
    if(y > x) cout << "y > x" << endl;      // (y <=> x) > 0
    if(z == x) cout << "z == x" << endl;    // (z == x)
    if(z != y) cout << "z != y" << endl;    // !(z == x)
    if(8 <=> x == 0) cout << "x == 8" << endl;
}