#include <iostream>
#include <exception>
using namespace std;


class MyInterface
{
public:
	virtual void f1() = 0;
	virtual void f2() = 0;
	virtual void f3() = 0;
	virtual void g1() = 0;
	virtual void g2() = 0;
	virtual void g3() = 0;
};

class MyClass : public MyInterface
{
public:
	void f1() {}
	void f2() {}
	void f3() {}
	void g1() {}
	void g2() {}
	void g3() {}
};

class MyClassProxy : public MyInterface
{
public:
	MyClassProxy() : p(new MyClass) {}
	void f1() { p->f1(); }
	void f2() { p->f2(); }
	void f3() { p->f3(); }
	void g1() { throw exception(); }
	void g2() { throw exception(); }
	void g3() { throw exception(); }
private:
	MyClass* p;
};

int main()
{
	MyClassProxy proxy;
	try 
	{
		proxy.f1();
		proxy.f2();
		proxy.f3();
		proxy.g1();
		proxy.g2();
		proxy.g3();
	}
	catch(exception e)
	{
		cout << e.what() << endl;
	}
}
