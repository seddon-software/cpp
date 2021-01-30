#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
 * enum classes are an improvement on enums
 * enum classes makes enumerations strongly typed
 * they don’t allow implicit conversion to int
 * and don’t allow comparisons from different enumerations
 */ 
enum class E : unsigned long
{
	E1 = 1,
	E2 = 2,
	Ebig = 0xFFFFFFF0U
};

template <typename E>
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
// these enums won't compile because BLUE is in both enums
	// enum Color {RED, GREEN, BLUE};
	// enum Feelings {EXCITED, MOODY, BLUE};

// but enum classes are OK with BLUE in both classes
	enum class Color {RED, GREEN, BLUE};
	enum class Feelings {EXCITED, MOODY, BLUE};

	cout << Color::BLUE << endl;
	cout << Feelings::BLUE << endl;

	// pass enum class item to function
	f(E::E1);
	f(E::E2);
	f(E::Ebig);
}
