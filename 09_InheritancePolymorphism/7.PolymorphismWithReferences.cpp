////////////////////////////////////////////////////////////
//
//      Polymorphism
//
////////////////////////////////////////////////////////////

/* 
 * Note: to view VTables in vscode you need to use the Debug Console:
 *      -exec vtbl s1
 *      -exec vtbl s2
 *      -exec vtbl b1 etc
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

void HideControl(Control& p)
{
    p.hide();
}

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

