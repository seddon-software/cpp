////////////////////////////////////////////////////////////
//
//		Adaptor Pattern (Object)
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


// this is the original class which we do not want to change
class ITarget
{
public:
	virtual void f1(int) = 0;
	virtual void f2(int) = 0;
};

class Target : public ITarget
{
public:
    virtual void f1(int x) 
	{ 
		cout << x << " " << x*2 << " " << x*4 << endl; 
	}
    virtual void f2(int x) 
	{ 
		cout << x << " " << x/2 << " " << x/4 << endl; 
	}
};

// this is the our class which uses the wrong interface
class OurClass
{
public:
	void g1(int x) { cout << x << " "; }
	void g2(int x) { cout << x*2 << " "; }
	void g3(int x) { cout << x*4 << " "; }
	void g4(int x) { cout << x/2 << " "; }
	void g5(int x) { cout << x/4 << " "; }
	void g6() { cout << endl; }
};


// this is the Adapter class
class Adapter : public ITarget
{
private:
	OurClass o;
public:
	virtual void f1(int x) { o.g1(x); o.g2(x); o.g3(x); o.g6(); }
	virtual void f2(int x) { o.g1(x); o.g4(x); o.g5(x); o.g6(); }
};

/////


void test(ITarget& target)
{
    target.f1(32);
    target.f2(20);
}

int main()
{
    Target t1;
    Target t2;
    Adapter adapter1;
    Adapter adapter2;

    // check we can use target and adapter objects
    test(t1);
    test(t2);
    test(adapter1);
    test(adapter2);
}

