#include <iostream>
using namespace std;

// use a helper class to specialize f()
template <typename U>
struct Helper
{
	static void f() { cout << "U" << endl; }
};

template <typename U>
struct Helper<U*>
{
	static void f() { cout << "U*" << endl; }
};

template <typename T, typename U>
struct A
{
public:
	A(T t0):t(t0){}
	void f1(T) {}
	void f2() {}
	// delegate to either generic Helper
	//                 or specialization helper
	void f3() { Helper<U>::f(); }
private:
	T t;
};


class X {};
class Y {};

/////

int main()
{
	X x;
	[[maybe_unused]]
	Y y;
	A<X,Y> a1(x);
	a1.f3();
	A<X,Y*> a2(x);
	a2.f3();
	return 0;
}

