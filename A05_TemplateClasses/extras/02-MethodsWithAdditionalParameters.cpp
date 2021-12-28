////////////////////////////////////////////////////////////
//
//      Methods that take additional template parameters
//
////////////////////////////////////////////////////////////


// in the templated class X, the function display takes 2 template parameters, but
// other methods only take 1 template parameter

#include <iostream>
using namespace std;

// define a template for iostream
template <typename T>
ostream& operator<<(ostream& os, const T& t)
{
	os << t.get();
	return os;
}

// define some example classes: A and B
class A
{
	// this is how you make the template a friend
	template <typename T> friend ostream& operator<<(ostream& os, const T& t);
public:
	A(int a) : a(a) {}
	int get() const { return a; }
private:
	int a;
};

class B
{
	// this is how you make the template a friend
	template <typename T> friend ostream& operator<<(ostream& os, const T& t);
public:
	B(int b) : b(b) {}
	int get() const { return b; }
private:
	int b;
};


// this class normally has 1 template parameter, but
// the display method takes an additional parameter
template <typename T>
class X
{
public:
    X(T t0):t0(t0) {}

	// this template has an additional template parameter
    template <typename U>
    void display(T t, U u)
    {
    	print(t);
    	print(u);
    }

    template <typename U>
    void print(U u)
    {
    	cout << u << endl;
    }
    
	// non templated method
    void print()
    {
    	cout << t0 << endl;
    }
private:
	T t0;
};


/////

int main()
{
	X<A> xa(33);
	A a(55);
	B b(77);
	cout << a << endl;
	cout << b << endl;
	xa.print();
	xa.display(a, b);
}

