#include <iostream>
#include <string>
using namespace std;


class Handler
{
public:
	virtual void Request(string) = 0;
};

class A : public Handler
{
public:
    void Request(string s) 
    {
    	if(s == "A")
    		cout << "request handled by A" << endl;
    	else
    		cout << "request NOT handled" << endl;
    }
};

class B : public Handler
{
private:
	Handler* pParent;
public:
    void setParent(Handler* pParent)
    {
    	 this->pParent = pParent;
    }

    void Request(string s) 
    {
    	if(s == "B")
    		cout << "request handled by B" << endl;
    	else
    		pParent->Request(s);
    }
};

class C : public Handler
{
private:
	Handler* pParent;
public:
    void setParent(Handler* pParent)
    {
    	 this->pParent = pParent;
    }

    void Request(string s) 
    {
    	if(s == "C")
    		cout << "request handled by C" << endl;
    	else
    		pParent->Request(s);
    }
};

int main()
{
    A a;
    B b;
    C c;
    c.setParent(&b);
    b.setParent(&a);

    c.Request("C");
    c.Request("B");
    c.Request("A");
    c.Request("X");
}
