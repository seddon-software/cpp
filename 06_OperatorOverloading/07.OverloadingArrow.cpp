#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
using namespace std;


class Time
{
public:
	Time(int h, int m):hrs(h), min(m) {}
	~Time()
	{
		cout << "Time DTOR called on:" << display() << endl;
	}
	void hello()
	{
		cout << "Hello called" << endl;
	}
	string display()
	{
		stringstream s;
		s << hrs << ":" << min << endl;
		return s.str();
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
		cout << "SmartPtr DTOR called for: " << ptr->display(); 
		delete ptr;
	}
	Time* operator->()  // overloaded -> as a unary operator
	{
		return ptr;
	}
private:
    Time* ptr;
};

void useSmartPtr(SmartPtr& s)
{
	s->hello();
		// ptr = s.operator->()
		// (*ptr).hello()

	// if we throw then the DTOR for s is called
	// this in turn calls the DTOR for the Time object ...
	// 	... and the heap gets cleaned up correctly
	throw runtime_error("was the heap cleaned up when we throw?");
}

int main()
{
	try
	{
		Time* p = new Time(2,15);
		Time* q = new Time(4,45);
		SmartPtr s1(p);
		SmartPtr s2(q);
		useSmartPtr(s1);
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
}
