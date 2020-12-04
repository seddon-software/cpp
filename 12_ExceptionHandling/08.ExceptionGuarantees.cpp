// Basic guarantee
//		The object is left in a valid state	and no resources, such as memory, are leaked.
//
// Strong guarantee
//		Provides the basic guarantee and is transactional (either the operation succeeds,
//      or has no effects)
//
// Nothrow guarantee
//		Guaranteed not to throw an exception
//

#include <stdexcept>
#include <iostream>
using namespace std;

class Time
{
public:
	Time(int h = 0, int m = 0) : hrs(h), min(m) {}
	void f3()
	{
		Time snapshot(*this);
		min += 1;
		if(min >= 60)
		{
			min -= 60;
			hrs += 1;
		}
		if (hrs >= 24)
		{
			*this = snapshot;		// on failure, operation has no effect
			throw runtime_error("strong guarantee");
		}
	}
	void f2()
	{
		min += 1;
		if(min >= 60)
		{
			min -= 60;
			hrs += 1;
		}
		if (hrs >= 24)
		{
			*this = Time(0, 0);		// reset the time
			throw runtime_error("basic guarantee");
		}
	}
	void f1()
	{
		min += 1;
		if(min >= 60)
		{
			min -= 60;
			hrs += 1;
		}
		if (hrs >= 24) throw runtime_error("no guarantee");
	}
	friend ostream& operator<<(ostream& os, const Time& t);
private:
	int hrs;
	int min;
};

ostream& operator<<(ostream& os, const Time& t)
{
	return os << t.hrs << "," << t.min;
}

int main()
{
	Time t;
	try
	{
		t = Time(23, 59);
		t.f3();
	}
	catch(runtime_error&)
	{
		cout << "Strong guarantee (rollback): " << t << endl;
	}
	try
	{
		t = Time(23, 59);
		t.f2();
	}
	catch(runtime_error&)
	{
		cout << "Basic guarantee (valid time): " << t << endl;
	}
	try
	{
		t = Time(23, 59);
		t.f1();
	}
	catch(runtime_error&)
	{
		cout << "No guarantee (invalid time): " << t << endl;
	}
}

