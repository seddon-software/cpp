////////////////////////////////////////////////////////////
//
//      Methods that take additional template parameters
//
////////////////////////////////////////////////////////////


// in the templated class X, the function display takes 2 template parameters, but
// other methods take 1 template parameter

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
// the method display takes an additional parameter
template <typename T>
class X
{
public:
    X() {}

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
};


/////

int main()
{
	X<A> xa;
	A a(55);
	B b(77);

	xa.display(a, b);

    return 0;
}

