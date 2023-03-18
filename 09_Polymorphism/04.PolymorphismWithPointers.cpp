/*
 * This is a similar example where we use references instead of pointers:
 *          void HideControl(Control& p)
 *          {
 *              p.hide();      // late binding
 *          }
 *
 * In this case late binding still works.
 * 
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

class Polygon : public Control
{
public:
    Polygon() {}
    virtual void show() { cout << "TextBox::show()" << endl; }
    virtual void hide() { cout << "TextBox::hide()" << endl; }
    virtual void draw() { cout << "TextBox::draw()" << endl; }
    virtual ~Polygon() { cout << "TextBox::DTOR" << endl; }
};

//////

void HideControl(Control& p)
{
    p.hide();      // late binding
}

int main()
{
    ScrollBar s1;
    ScrollBar s2;
    Button    b1;
    Button    b2;
    Polygon   t1;
    Polygon   t2;

    HideControl(s1);
    HideControl(s2);
    HideControl(b1);
    HideControl(b2);
    HideControl(t1);
    HideControl(t2);
}

