////////////////////////////////////////////////////////////
//
//      Polymorphism
//
////////////////////////////////////////////////////////////

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

    for (int i = 0; i < theList.size(); ++i)
    {
        HideControl(theList[i]);
    }
}

