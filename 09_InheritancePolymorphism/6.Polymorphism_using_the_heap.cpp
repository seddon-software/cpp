////////////////////////////////////////////////////////////
//
//      Polymorphism
//
////////////////////////////////////////////////////////////

/* 
 * Note: to view VTables in vscode you need to use the Debug Console:
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

void HideControl(Control* p)
{
    p->hide();
}

int main()
{
    // create all our controls on the heap
    vector<Control*> theList;
    theList.push_back(new ScrollBar());
    theList.push_back(new ScrollBar());
    theList.push_back(new Button());
    theList.push_back(new Button());
    theList.push_back(new TextBox());
    theList.push_back(new TextBox());

    for (unsigned i = 0; i < theList.size(); ++i)
    {
        HideControl(theList[i]);
    }

    // clean up the heap
    for(auto& ptr : theList)
    {
        delete ptr;   
    }
}

