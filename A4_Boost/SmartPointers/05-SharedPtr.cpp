////////////////////////////////////////////////////////////
//
//		Scoped Pointer
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <boost/shared_ptr.hpp>
using namespace std;


class mystring
{
private:
    string s;
public:
    mystring(const char* s) : s(s) { cout << "CTOR" << endl; } 
    ~mystring() { cout << "DTOR" << endl; } 
    
    void append(const char* end) 
    {
        s += end;
    }
    void print()
    {
        cout << s << endl;
    }
};

typedef boost::shared_ptr<mystring> SHARED_PTR;

class A
{
public:
	A(const SHARED_PTR& n) : name(n) {}
    void print()
    {
        name->print();
    }
private:
	SHARED_PTR name;
};

class B
{
public:
	B(const SHARED_PTR& n) : name(n) {}
    void print()
    {
        name->print();
    }
private:
	SHARED_PTR name;
};

/////

int main()
{
    {
	    SHARED_PTR x(new mystring("shared string"));
        A a(x);
        B b(x);
        x->append(" is reference counted");
        cout << "Reference count = " << x.use_count() << endl;
        x->print();
        a.print();
        b.print();
    }   
	return 0;
}
