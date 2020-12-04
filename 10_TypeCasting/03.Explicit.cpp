///////////////////////////////////////////////////////////////
//
//		Explicit
//
///////////////////////////////////////////////////////////////

/*
 *  The explicit keyword on a operator cast or constructor cast
 *  prevents the cast being used implicitly.  This is to prevent
 *  cast operations occuring that were not intended by the program author.
 */

#pragma GCC diagnostic ignored "-Wunused-variable"
#include <iostream>
using namespace std;

class Time
{
public:
	Time() 
	:
		hours  (0),
		minutes(0)
	{}

	// explicit Time(int m)
	Time(int m)
	:
		hours(m/60),
		minutes(m%60)
	{}

	// explicit operator int()
	operator int()
	{
		return hours * 60 + minutes;
	}
private:
	int hours;
	int minutes;
};

/////

int main()
{
	Time t;
	int x1 = 150;

	// implicit casts
	t = x1;
	int x2 = t;

	// explicit casts
	t = static_cast<Time>(x1);
	int x3 = static_cast<int>(t);
}
