#include <iostream>
using namespace std;

// one constructor can call another to avoid repeating code
class X
{
public:
	X(int i) : i(i) {}
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
