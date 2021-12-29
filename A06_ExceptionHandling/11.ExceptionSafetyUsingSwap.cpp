////////////////////////////////////////////////////////////////////////////
//
//  Exception Safety using Swap
//
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
using namespace std;

struct MyException : public exception
{
    MyException(const string& message) : message(message) {}
    virtual const char* what() const noexcept
    {
        return message.c_str();
    }
    string message;
};

// simple class to use with widget
class X
{
public:
    X(int x = 0) : x(x) { if (x > 4) throw runtime_error("X must be <= 4"); }
    X(const X& rhs) : x(rhs.x) { if (x > 4) throw runtime_error("X must be <= 4"); }
    X& operator+=(int i)
    {
        x += i;
        if(x > 4) throw MyException("Rollback: component must be < 5");
        return *this;
    }
    int get() { return x; }
private:
    int x;
};


template <typename T>
class Widget
{
public:
    Widget() {}
    Widget(const T& t1, const T& t2): t1(t1), t2(t2) {}
    Widget& operator+=(int)  // this might throw
    {
        try
        {
            Widget temp;
            temp = *this;
            temp.t1 += 1;
            temp.t2 += 1;
            Swap(temp);       // Swap temp and *this
        }
        catch(...)
        {
            cout << "operator+=() failed, so performing rollback" << endl;
        }
        return *this;
    }
    void print(const string& id)
    {
        cout << id << ": " << t1.get() << "," << t2.get() << endl;
    }
    void Swap(Widget& other) noexcept
    // doesn't throw
    {
        Widget temp;
        temp.t1 = t1;
        temp.t2 = t2;
        *this = temp;
    }
private:
    X t1;
    X t2;
};


int main()
{
    Widget<X> w1(X(1), X(2));
    Widget<X> w2(X(3), X(4));
    w1.print("w1"); w2.print("w2");
    try 
    {
        w2 += 1;        // this will throw, because component w2 > 4, but swap ensures rollback
    } 
    catch(const MyException& e) 
    {
        cout << e.what() << endl;
    }
    w1.print("w1"); w2.print("w2");
}
