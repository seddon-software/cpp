#include <compare>
#include <iostream>
using namespace std;

class X
{
private:
    int a;
    int b;
    // for comparisons we consider the value of an object x of X to be x.a + x.b
public:
    explicit X(int a, int b): a(a), b(b) {}
    // define primary operators == and <=> for int and constX&
    bool operator==(int rhs) const
    {
        int lhs = a + b;
        return lhs == rhs;
    }
    bool operator==(const X& other) const
    {
        int lhs = a + b;
        int rhs = other.a + other.b;
        return lhs == rhs;
    }
    strong_ordering operator<=>(int rhs) const
    {
        int lhs = a + b;
        if(lhs == rhs)     return strong_ordering::equal;
        else if(lhs < rhs) return strong_ordering::less;
        else               return strong_ordering::greater;
    }
    strong_ordering operator<=>(const X& other) const
    {
        int lhs = a + b;
        int rhs = other.a + other.b;
        if     (lhs == rhs) return strong_ordering::equal;
        else if(lhs < rhs)  return strong_ordering::less;
        else                return strong_ordering::greater;
    }
};

int main()
{
    X x(3, 5);
    X y(4, 7);
    X z(2, 6);
    if(x < y) cout << "x < y" << endl;
    if(x < 10) cout << "x < 10" << endl;
    if(x >= 8) cout << "x >= 8" << endl;
    if(x > y) cout << "x > y" << endl;
    if(y > x) cout << "y > x" << endl;
    if(z == x) cout << "z == x" << endl;
    if(8 <=> x == 0) cout << "x == 8" << endl;
}