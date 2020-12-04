////////////////////////////////////////////////////////////
//
//		Smart Pointers
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class Time
{
private:
	int hours;
	int minutes;
public:
	Time(int h, int m) : hours(h), minutes(m) 
	{
		cout << "CTOR called" << endl;
	}

	~Time() 
	{
		cout << "DTOR called" << endl;
	}
	
	void Print() const
	{ 
		cout << hours << ":" << minutes << endl; 
	}
};

/////

class TimePtr
{
public:
	TimePtr() : ptr(0)
	{}

	TimePtr(int h, int m) : ptr(new Time(h,m))
	{}

	~TimePtr()
	{
		delete ptr;
	}

	const Time* operator->()
	{
		if (ptr == 0) throw "pointer is null";
		return ptr;
	}

	void operator=(Time* const p)
	{
		ptr = p;
	}

private:
	Time* ptr;
};

/////

int main()
{
	TimePtr p1(1, 15);
	TimePtr p2(2, 30);
	TimePtr p3(3, 45);
	TimePtr q;

	p1->Print();	 // p1.operator->() -> Print();
	p2->Print();
	p3->Print();

	try
	{
		q->Print();
	}
	catch(const char* message)
	{
		cout << message << endl;
	}
	return 0;
}

