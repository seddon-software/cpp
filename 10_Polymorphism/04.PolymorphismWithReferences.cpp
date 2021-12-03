////////////////////////////////////////////////////////////
//
//      Polymorphism
//
////////////////////////////////////////////////////////////

/* 
 * Note: to view VTables in vscode you need to use the Debug Console:
 *      -exec info vtbl s1
 *      -exec info vtbl s2
 *      -exec info vtbl b1 etc
 * to view the pointer to the VTable embedded in each object
 *      -exec p s1
 */

#include <vector>
#include <iostream>
using namespace std;


class Control
{
public:
    Control() {}
    virtual void show() { cout << "Control::show()" << endl; }  // dummy implementation for demo
    virtual void hide() { cout << "Control::hide()" << endl; }
    virtual void draw() { cout << "Control::draw()" << endl; }
    virtual ~Control() { cout << "Control::DTOR" << endl; }
};

class ScrollBar : public Control
{
public:
    ScrollBar() {}
    virtual void show() { cout << "ScrollBar::show()" << endl; }
    virtual void hide() { cout << "ScrollBar::hide()" << endl; }
    virtual void draw() { cout << "ScrollBar::draw()" << endl; }
    virtual ~ScrollBar() { cout << "ScrollBar::DTOR" << endl; }
};

class Button : public Control
{
public:
    Button() {}
    virtual void show() { cout << "Button::show()" << endl; }
    virtual void hide() { cout << "Button::hide()" << endl; }
    virtual void draw() { cout << "Button::draw()" << endl; }
    virtual ~Button() { cout << "Button::DTOR" << endl; }
};

class TextBox : public Control
{
public:
    TextBox() {}
    virtual void show() { cout << "TextBox::show()" << endl; }
    virtual void hide() { cout << "TextBox::hide()" << endl; }
    virtual void draw() { cout << "TextBox::draw()" << endl; }
    virtual ~TextBox() { cout << "TextBox::DTOR" << endl; }
};

//////

void HideControl(Control& p)
{
    p.hide();
}

/*
    If a method is marked as virtual in the base class, the compiler creates
    one V-Table per class and places a pointer to the V-Table in every object:

          s1                   ScrollBar V-Table
     ┌──────────┐      ┌───────────────────────────────┐
     │  _vptr   │----->│ ScrollBar::show() {...}       │
     │   ...    │  │   │ ScrollBar::hide() {...}       │
     └──────────┘  │   │ ScrollBar::draw() {...}       │
          s2       │   │ ScrollBar::~ScrollBar() {...} │
     ┌──────────┐  │   └───────────────────────────────┘
     │  _vptr   │--┘
     │   ...    │ 
     └──────────┘

          b1                   Button V-Table
     ┌──────────┐      ┌───────────────────────────────┐
     │  _vptr   │----->│ Button::show() {...}          │
     │   ...    │  │   │ Button::hide() {...}          │
     └──────────┘  │   │ Button::draw() {...}          │
          b2       │   │ Button::~Button() {...}       │
     ┌──────────┐  │   └───────────────────────────────┘
     │  _vptr   │--┘
     │   ...    │ 
     └──────────┘

          t1                   TextBox V-Table
     ┌──────────┐      ┌───────────────────────────────┐
     │  _vptr   │----->│ TextBox::show() {...}         │
     │   ...    │  │   │ TextBox::hide() {...}         │
     └──────────┘  │   │ TextBox::draw() {...}         │
          t2       │   │ TextBox::~TextBox() {...}     │
     ┌──────────┐  │   └───────────────────────────────┘
     │  _vptr   │--┘
     │   ...    │ 
     └──────────┘
*/
int main()
{
    ScrollBar s1;
    ScrollBar s2;
    Button    b1;
    Button    b2;
    TextBox   t1;
    TextBox   t2;

    HideControl(s1);
    HideControl(s2);
    HideControl(b1);
    HideControl(b2);
    HideControl(t1);
    HideControl(t2);
}

