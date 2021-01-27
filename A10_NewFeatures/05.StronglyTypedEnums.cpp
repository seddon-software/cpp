#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


enum class E : unsigned long
{
	E1 = 1,
	E2 = 2,
	Ebig = 0xFFFFFFF0U
};

ostream& operator<<(ostream& os, E e)
{
	// implicit conversion to/from int not allowed, but can use:
	os << hex << static_cast<unsigned long>(e);
	return os;
}

void f(enum E e)
{
	cout << e << endl;
}

int main()
{
	// this code will not compile (BLUE is in both enums)
//	enum class Color {RED, GREEN, BLUE};
//	enum class Feelings {EXCITED, MOODY, BLUE};	f(E::E1);

	// no problems with enum class
	enum class Color {RED, GREEN, BLUE};
	enum class Feelings {EXCITED, MOODY, BLUE};

	// pass enum class to function
	f(E::E1);
	f(E::E2);
	f(E::Ebig);
}
