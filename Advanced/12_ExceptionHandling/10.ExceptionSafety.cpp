#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
using namespace std;

class X
{
public:
    X(int x = 0) : x(x) {}
    X(const X& rhs) : x(rhs.x)
    {
        if (x > 4) throw runtime_error("X must be <= 4");
    }
    X& operator+=(int i)
    {
        x += i;
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
    Widget(const T& x1, const T& x2);
    Widget& operator=(const Widget&);
    Widget& operator+=(int);
    void print(const string&);
public:
    class WidgetImpl;
    void Swap(Widget& other) noexcept;
    shared_ptr<WidgetImpl> ptr;
};

template <typename T>
class Widget<T>::WidgetImpl
{
public:
    WidgetImpl(const T& t1, const T& t2) : t1(t1), t2(t2) {}
    X t1;
    X t2;
};

template <typename T>
Widget<T>::Widget(const T& x1, const T& x2)
    : ptr(shared_ptr<WidgetImpl>(new WidgetImpl(x1, x2))) {}

template <typename T>
void Widget<T>::Swap(Widget& other) noexcept
{
    shared_ptr<WidgetImpl> temp = ptr;
    ptr = other.ptr;
    other.ptr = temp;
}

template <typename T>
void Widget<T>::print(const string& id)
{
    cout << id << ": " << ptr->t1.get() << "," << ptr->t2.get() << endl;
}

template <typename T>
Widget<T>& Widget<T>::operator=(const Widget<T>& other)
{
    Widget temp(other.ptr->t1, other.ptr->t2);	// this may throw, but *this is unchanged
    Swap(temp);    								// the "commit" can't throw
    return *this;
}

template <typename T>
Widget<T>& Widget<T>::operator+=(int i)
{
    ptr->t2 += 1;
    return *this;
}

int main()
{
    {
        cout << "commit - w1 and w2 should be equal" << endl;
        Widget<X> w1(X(1), X(2));
        Widget<X> w2(X(3), X(4));
        try { w1 = w2; }
        catch (...) {}
        w1.print("w1"); w2.print("w2");
    }
    {
        cout << "rollback - w1 and w2 should retain their original values" << endl;
        Widget<X> w1(X(1), X(2));
        Widget<X> w2(X(3), X(4));
        w2 += 1;
        w1.print("w1"); w2.print("w2");
        try { w1 = w2; }
        catch (...) {}
        w1.print("w1"); w2.print("w2");
    }
}
