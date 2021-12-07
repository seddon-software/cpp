////////////////////////////////////////////////////////////
//
//      Binding
//
////////////////////////////////////////////////////////////

/* 
 * Early binding is when the compiler decides which method to call at compile time
 * Late binding is when the compiler defers the decision until run time
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

