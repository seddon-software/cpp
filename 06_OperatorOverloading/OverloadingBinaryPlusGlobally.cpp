#include <iostream>

using namespace std;

class Time
{
	friend Time operator+(const Time& s1, const Time& s2);
public:
	Time(): hrs(0), min(0) {}					// default CTOR
	Time(int h, int m): hrs(h), min(m) {}
	Time(const Time& t): hrs(t.hrs), min(t.min)
	{
		cout << "Copy CTOR" << endl;
	}		// Copy CTOR
	~Time()
	{
		cout << "DTOR" << endl;
	}
	const Time& operator=(const Time& rhs)  // *this = rhs
	{
		cout << "operator=" << endl;
		hrs = rhs.hrs;
		min = rhs.min;
		return *this;
	}
	Time& operator+=(const Time& rhs)   // *this += rhs
	{
		*this = *this + rhs;
		return *this;
	}
private:
	int hrs;
	int min;
};

Time operator+(const Time& s1, const Time& s2)
{
	Time t;
	t.hrs = s1.hrs + s2.hrs;
	t.min = s1.min + s2.min;
	if(t.min >= 60)
	{
		t.hrs++;
		t.min -= 60;
	}
	return t;
}

int main()
{
	Time t;				// uses default CTOR()
	Time t1(4, 15);		// uses CTOR(int, int)
	Time t2(2, 50);
	Time t3(t1);		// uses CTOR(Time)
	t = t1 + t2;	// t = operator+(t1, t2);
	t1 = t = t3;				// t1 = t.operator=(t3)
	t2 += t3;			//  ... = t2.operator+=(t3)
}






