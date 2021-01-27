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


int main()
{
    ScrollBar s1;
    ScrollBar s2;
    Button    b1;
    Button    b2;
    TextBox   t1;
    TextBox   t2;

    s1.Control::Hide();  // early binding
    s1.Hide();           // late binding
}

