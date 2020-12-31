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

void HideControl(Control& p)
{
    p.Hide();
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

