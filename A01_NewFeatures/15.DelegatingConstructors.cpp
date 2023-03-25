#include <iostream>
using namespace std;

/*  
 *  One feature that was missing from C++ was the ability of a CTOR to call another CTOR to
 *  reduce code duplication.  This feature was added to C++11.
 * 
 *  A rather simplistic example is given below.  The default CTOR makes a call to the X(int)
 *  CTOR to initialize objects.  Obviously, it would be preferable to initialize the instance 
 *  variable directly, but the example does show one CTOR calling another.
 */

class X
{
public:
	X(int i) : i(i) {}
    // one constructor can call another to avoid repeating code
	X(): X(42) {}   // CTOR calling another CTOR
	int get() { return i; }
private:
	int i;
};

int main()
{
	X x1;
	X x2(25);
	cout << x1.get() << endl;
	cout << x2.get() << endl;
}
