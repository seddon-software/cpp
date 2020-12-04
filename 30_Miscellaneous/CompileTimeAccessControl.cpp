///////////////////////////////////////////////////////////////
//
//		Compile Time Access Control
//
///////////////////////////////////////////////////////////////

class Base
{ 
public:
    virtual void f1() {}
};

class Derived : public Base
{
private:
    virtual void f1() {}
};

/////

int main()
{
    Base* ptr;

    ptr = new Base;
    ptr->f1();

    ptr = new Derived;
    ptr->f1();          // f1() is private!!

	return 0;
}
