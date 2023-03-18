/* 
 * Polymorphism is where we have many (poly) forms (morphic) of a given method in an inheritance hierarchy.
 *
 * With inheritance the compiler has 2 different ways of binding an object to a method:
 *      Early binding is when the compiler determines which method to call at compile time.
 *      Late binding is when the compiler defers the decision until run time.
 * 
 * Because of the SUBSTITUTION RULE the compiler can't detrmine which object is passed to a function if
 * a reference is used.  The rule states that and derived object could be passed as a substitute for the 
 * base class objec.  This in turn means the compiler can't determine witch polymorphic method to call
 * at compile time and needs to defer a decision on object/function binding until run time.
 * 
 * As we have seen, passing a polymorphic object by reference to a function is not sufficient to ensure
 * late binding is used; C++ requires methods to be also marked as 'virtual' before late binding occurs.
 * It may seem that declaring a method virtual is excessive, but at the time when Bjarne Stroustrup
 * introduced polymorphic functions, he was worried that late binding might be too inefficient.  Languages
 * that followed C++'s lead have dispensed with virtual functions and only require a reference to employ 
 * late binding.
 * 
 * Nevertheless we have to use virtual functions in C++.  It should be noted that the term virtual function
 * is a misnomer - there is nothing virtual about these functions. 
 * 
 * In this example we again create a free function that takes a polymorhic object by reference, but this
 * time all the class methods are marked virtual.  As we will see shortly this results in the compiler 
 * employing late binding in the function below:
 *          void hideAnyControl(Control& c)
 *          {
 *              c.hide();    // late binding, runtime binding, dynamic binding
 *          }
 * 
 * With early binding, the base class method always gets called, which is normally not what is desired.  
 * Why else would we write a polymorphic version of the method in the derived classes?
 * 
 * Note that:
 *  early binding can also be called 1) compile time binding or 2) static binding
 *  late binding  can also be called 1) runtime binding or      2) dynamic binding
 */

#include <vector>
#include <iostream>
using namespace std;


class Control
{
public:
    virtual void show() { cout << "Control::show()" << endl; }  // dummy implementation for demo
    virtual void hide() { cout << "Control::hide()" << endl; }
    virtual void update() { cout << "Control::update()" << endl; }
    virtual ~Control() { cout << "Control::DTOR" << endl; }
};

class ScrollBar : public Control
{
public:
    ScrollBar() {}
    virtual void show() { cout << "ScrollBar::show()" << endl; }
    virtual void hide() { cout << "ScrollBar::hide()" << endl; }
    virtual void update() { cout << "ScrollBar::update()" << endl; }
    virtual ~ScrollBar() { cout << "ScrollBar::DTOR" << endl; }
};

class Button : public Control
{
public:
    Button() {}
    virtual void show() { cout << "Button::show()" << endl; }
    virtual void hide() { cout << "Button::hide()" << endl; }
    virtual void update() { cout << "Button::update()" << endl; }
    virtual ~Button() { cout << "Button::DTOR" << endl; }
};

class Polygon : public Control
{
public:
    Polygon() {}
    virtual void show() { cout << "TextBox::show()" << endl; }
    virtual void hide() { cout << "TextBox::hide()" << endl; }
    virtual void update() { cout << "TextBox::update()" << endl; }
    virtual ~Polygon() { cout << "TextBox::DTOR" << endl; }
};

//////
// pass c by reference
// the compiler can't tell if its a ScrollBar, Button, or TextBox
// hence c and hide() are bound at runtime
void hideAnyControl(Control& c)
{
    c.hide();    // late binding, runtime binding, dynamic binding
}

int main()
{
    ScrollBar s1;
    ScrollBar s2;
    Button    b1;
    Button    b2;
    Polygon   t1;
    Polygon   t2;
    Control c;
    
    hideAnyControl(s1);
    hideAnyControl(s2);
    hideAnyControl(b1);
    hideAnyControl(b2);
    hideAnyControl(t1);
    hideAnyControl(t2);

    s1.hide();           // early binding, compile time binding, static binding
    s1.Control::hide();  // early binding, compile time binding, static binding
}

