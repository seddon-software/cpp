#include <iostream>
using namespace std;


class Time
{
public:
	Time(int h, int m):hrs(h), min(m) {}
	~Time()
	{
		cout << "Time DTOR" << endl;
	}
	void display()
	{
		cout << hrs << ":" << min << endl;
	}
private:
	int hrs;
	int min;
};

class SmartPtr
{
public:
	SmartPtr(Time* p) : ptr(p) {}
	~SmartPtr()
	{
		delete ptr;
	}
	Time* operator->()
	{
		return ptr;
	}
private:
    Time* ptr;
};

void useSmartPtr(SmartPtr& s)
{
	s->display();			// ptr = s.operator->()
	                        // ptr->hello()
	// if we throw then the DTOR for s is called
	// this in turn calls the DTOR for the Time object ...
	// 	... and the heap is cleaned up correctly
	throw "was the heap cleaned up when we throw?";
}

int main()
{
	try
	{
		SmartPtr s(new Time(2,15));
		useSmartPtr(s);
	} catch(const char* e) {
		cout << e << endl;
	}
}
