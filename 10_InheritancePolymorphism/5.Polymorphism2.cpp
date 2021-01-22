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
    virtual void Show() {}  // dummy implementation for demo
    virtual void Hide() {}
    virtual void Update() {}
    virtual ~Control() { cout << "Control DTOR" << endl; }
};

class ScrollBar : public Control
{
public:
    ScrollBar() {}
    virtual void Show() {}
    virtual void Hide() {}
    virtual void Update() {}
    ~ScrollBar() { cout << "ScrollBar DTOR" << endl; }
};

class Button : public Control
{
public:
    Button() {}
    virtual void Show() {}
    virtual void Hide() {}
    virtual void Update() {}
    ~Button() { cout << "Button DTOR" << endl; }
};

class TextBox : public Control
{
public:
    TextBox() {}
    virtual void Show() {}
    virtual void Hide() {}
    virtual void Update() {}
    ~TextBox() { cout << "TextBox DTOR" << endl; }
};

//////

void HideControl(Control* p)
{
    p->Hide();
}

int main()
{
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

    for(auto& ptr : theList)
    {
        delete ptr;   
    }
}

