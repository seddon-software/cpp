#include <iostream>
using namespace std;

class X
{
public:
	X(int i) : i(i) {}
	// CTOR calling another CTOR
	X(): X(42) {}
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
	return 0;
}
