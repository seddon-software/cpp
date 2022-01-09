////////////////////////////////////////////////////////////////////////////
//
//  Exception Safety using Swap
//
////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <memory>
using namespace std;

/*
 *  This is a somewhat artificial example to illustrate how to use std::swap to ensure exception safety.
 *  We first create a class X that wraps an integer x.  Note that the CTOR throws if x > 4.
 * 
 *  Next we create a Widget class that has two X components.  The widget class overrides the += operator
 *  in an exception safe way.  To do this we make use of std::swap (which doesn't throw).  
 * 
 *  In operator+=() we take a copy of *this and try to increment *this.  This involves incrementing
 *  both X components.  Clearly this might throw, but if it does, no harm is done because we only 
 *  modified a copy of *this.  Thus if we throw, the routine will not change *this.
 * 
 *  If we don't throw we can proceed to swap the copy with *this and since std::swap doesn't throw we 
 *  are exception safe.  
 *  
 *  So either we throw and *this is left unchanged or the += succeeds.
 */

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
    X(int x = 0) : x(x) { if (x > 4) throw MyException("X must be <= 4"); }
    X(const X& rhs) : x(rhs.x) { if (x > 4) throw MyException("X must be <= 4"); }
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
            std::swap(temp, *this);       // Swap temp and *this
        }
        catch(const MyException& e)
        {
            cout << e.what() << endl;
            cout << "operator+=() failed, so performing rollback" << endl;
        }
        return *this;
    }
    void print(const string& id)
    {
        cout << id << ": " << t1.get() << "," << t2.get() << endl;
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
        w1 += 1;
        w1.print("w1"); // this succeeds
        w2 += 1;        // this will throw, because component w2 > 4, but swap ensures rollback
    } 
    catch(const MyException& e) 
    {
        cout << e.what() << endl;
    }
    w1.print("w1"); w2.print("w2");
}
