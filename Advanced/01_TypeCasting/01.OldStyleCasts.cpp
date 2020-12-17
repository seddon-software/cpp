////////////////////////////////////////////////////////////
//
//		Old Style Casts
//
////////////////////////////////////////////////////////////

/*
 *   Old style casts are implemented in C++ using member functions:
 *   1) operator T():				to convert to T
 *   2) single parameter CTOR(T):	to convert from T
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
