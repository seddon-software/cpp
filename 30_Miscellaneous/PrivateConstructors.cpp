///////////////////////////////////////////////////////////////
//
//		Private Constructors
//
///////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class X
{
public:
    static X* Create(int n)
    {
        if(count == 3) throw "No more objects allowed"; 
        count++;
        return new X(n);
    }

private:
    X(int x0) : x(x0) {}    // private CTOR
    [[ maybe_unused ]] int x;
    static int count;
};

int X::count = 0;   // class static data


int main()
{
    try
    {
    	typedef X *XPTR;
        XPTR p1, p2, p3, p4;
        p1 = X::Create(100);
        p2 = X::Create(200);
        p3 = X::Create(300);
        p4 = X::Create(400);
    }
    catch(char* message)
    {
        cout << message << endl;
    }
}

