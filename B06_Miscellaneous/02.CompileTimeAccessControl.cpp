
/*
 *  It's often assumed that if a method is declared private then you can't access it.  However, this isn't
 *  quite true, as this example shows.  What is true is that a private method can only be called through
 *  v-tables as the private attribute is a compile time check - not a run-time one.
 */

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
}
