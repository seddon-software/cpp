////////////////////////////////////////////////////////////
//
//		Using global operator+
//
////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;


template <typename T>
T operator+(const T& lhs, const T& rhs)
{
	return lhs.get() + rhs.get();
}

class A
{
public:
	A(int a = 0) : a(a) {}
	int get() const { return a; }
private:
	int a;
};

class B
{
public:
	B(int b = 0) : b(b) {}
	int get() const { return b; }
private:
	int b;
};

class C
{
public:
	C(int c = 0) : c(c) {}
	int get() const { return c; }
private:
	int c;
};


/////

int main()
{
	A a1(10), a2(20), a3;
	B b1(12), b2(24), b3;
	C c1(15), c2(30), c3;

	a3 = a1 + a2;
	b3 = b1 + b2;
	c3 = c1 + c2;

	cout << a3.get() << endl;
	cout << b3.get() << endl;
	cout << c3.get() << endl;
}

