////////////////////////////////////////////////////////////
//
//		Decorator
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// this is the original Component hierachy
class Component
{
public:
	virtual void f() = 0;
};

class ConcreteComponent : public Component
{
public:
	virtual void f() { cout << "concrete" << endl; }
};


// this is the Decorator hierarchy
class Decorator : public Component
{
private:
	Component *pComponent;
public:
    Decorator(Component* ptr = 0) :pComponent(ptr) {}
	virtual void f() 
    { 
         pComponent->f(); 
    }
};

class DecoratorA : public Decorator
{
public:
    DecoratorA(Component* ptr = 0) :Decorator(ptr) {}
	virtual void f() 
    {          
        Decorator::f(); 
        g(); 
    }
private:
    virtual void g() 
    {
        cout << "decoration A" << endl; 
    }
};

class DecoratorB : public Decorator
{
public:
    DecoratorB(Component* ptr = 0) :Decorator(ptr) {}
	virtual void f() 
    { 
        Decorator::f(); 
        g(); 
    }
private:
	virtual void g() 
    {
        cout << "decoration B" << endl; 
    }
};

/////

int main()
{
    // chain decorators
    ConcreteComponent concrete;
    DecoratorA decoratorA(&concrete);
    DecoratorB decoratorB(&decoratorA);

    decoratorB.f();
}

