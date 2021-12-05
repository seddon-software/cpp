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

using namespace std;


class Control
{
public:
    Control() {}
    virtual void Show() {}  // dummy implementation for demo
    virtual void Hide() {}
    virtual void Update() {}
};

class ScrollBar : public Control
{
public:
    ScrollBar() {}
    virtual void Show() {}
    virtual void Hide() {}
    virtual void Update() {}
};

class Button : public Control
{
public:
    Button() {}
    virtual void Show() {}
    virtual void Hide() {}
    virtual void Update() {}
};

class TextBox : public Control
{
public:
    TextBox() {}
    virtual void Show() {}
    virtual void Hide() {}
    virtual void Update() {}
};

//////

void HideControl(Control* p)
{
    p->Hide();
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

    vector<Control*> theList;
    theList.push_back(&s1);
    theList.push_back(&s2);
    theList.push_back(&b1);
    theList.push_back(&b2);
    theList.push_back(&t1);
    theList.push_back(&t2);

    for (unsigned i = 0; i < theList.size(); ++i)
    {
        HideControl(theList[i]);
    }
}

