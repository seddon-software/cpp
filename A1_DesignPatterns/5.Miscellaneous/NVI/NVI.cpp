////////////////////////////////////////////////////////////
//
//		NVI
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


class Base
{
private:
	virtual void one() = 0;
	virtual void two() = 0;
public:
    void doOperation() {
    	one();
    	two();
    }
};

class D1 : public Base
{
	virtual void one() {}
	virtual void two() {}
};

class D2 : public Base
{
	virtual void one() {}
	virtual void two() {}
};


/////

int main()
{
    D1 d1;
    D2 d2;
    d1.doOperation();
    d2.doOperation();
}
