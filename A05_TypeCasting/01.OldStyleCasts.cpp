////////////////////////////////////////////////////////////
//
//		Old Style Casts
//
////////////////////////////////////////////////////////////

/*
 *  Old style casts are implemented in using member functions of class T (where U is a built in type):
 *        1) T::operator U():				to convert T to U
 *        2) T::T(U):                      	to convert from U to T
 * 
 *  It is also possible to convert between classes U and T where U is a class and not a built in type.  In
 *  that case we choose 2 conversions from:
 *        1) T::operator U():				to convert T to U           OR
 *           U::U(T):                      	to convert from T to U
 *        2) U::operator T():				to convert U to T           OR
 *           T::T(U):                      	to convert from U to T
 * 
 *  In this example we restrict ourselves to the built in type example and use:
 * 	        Time::operator int()            to convert Time to int
 *          Time::Time(int)                 to convert from int to Time
 */

#include <iostream>
using namespace std;

class Time
{
public:
	// cast to int
	operator int()
	{
		return hrs * 60 + min;
	}
	// single parameter CTOR is cast from int
	Time(int min):hrs(min/60), min(min%60) {}
	Time(int hrs, int min):hrs(hrs), min(min) {}
	Time():hrs(0), min(0) {}
	friend ostream& operator<<(ostream& os, const Time& t);
private:
	int hrs;
	int min;
};

ostream& operator<<(ostream& os, const Time& t)
{
	return os << t.hrs << ":" << t.min;
}

int main()
{
	Time t(5, 15);
	int minutes;
	minutes = t;
	cout << minutes << endl;
	Time t2;
	t2 = (Time) minutes;
	cout << t2 << endl;
}
