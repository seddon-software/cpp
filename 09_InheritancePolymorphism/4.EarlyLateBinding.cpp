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

class TextBox : public Control
{
public:
    TextBox() {}
    virtual void show() { cout << "TextBox::show()" << endl; }
    virtual void hide() { cout << "TextBox::hide()" << endl; }
    virtual void update() { cout << "TextBox::update()" << endl; }
    virtual ~TextBox() { cout << "TextBox::DTOR" << endl; }
};

//////


int main()
{
    ScrollBar s1;
    ScrollBar s2;
    Button    b1;
    Button    b2;
    TextBox   t1;
    TextBox   t2;

    s1.Control::hide();  // early binding
    s1.hide();           // late binding
}

