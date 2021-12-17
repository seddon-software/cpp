///////////////////////////////////////////////////////////////
//
//		Masking Base Class Methods
//
///////////////////////////////////////////////////////////////

class Base
{ 
public:
    void f1(int) {}
};

class Derived : private Base
{
public:
    using Base::f1;    // republish to make visible
    void f1() {}
private:
};

/////

int main()
{
    Derived d;
    d.f1(4); // doesn't compile without using declaration
	return 0;
}
