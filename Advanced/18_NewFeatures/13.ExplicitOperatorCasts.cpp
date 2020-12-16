#include <iostream>
using namespace std;

class Time1		// explicit casts
{
public:
	Time1() :hrs(0), min(0) {}
	Time1(int h, int m) : hrs(h), min(m) {}
	explicit Time1(int m) : hrs(m/60), min(m%60) {}
	explicit operator int() { return hrs * 60 + min; }
private:
	int hrs;
	int min;
};

class Time2		// implicit casts
{
public:
	Time2() :hrs(0), min(0) {}
	Time2(int h, int m) : hrs(h), min(m) {}
	Time2(int m) : hrs(m/60), min(m%60) {}
	operator int() { return hrs * 60 + min; }
private:
	int hrs;
	int min;
};


void test1()
{
	// explicit conversions required for Time1 class
	Time1 t1(5,25), t2;
	int m;
	m = static_cast<int>(t1);
	t2 = static_cast<Time1>(m);
}

void test2()
{
	// implicit conversions allowed for Time2 class
	Time2 t1(5,25), t2;
	int m;
	m = t1;
	t2 = m;
}

int main()
{
	test1();
	test2();
}
