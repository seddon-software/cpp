#include <iostream>
using namespace std;


class Time
{
public:
	Time(int h, int m):hrs(h), min(m) {}
	~Time()
	{
		cout << "DTOR" << endl;
	}
	void display()
	{
		cout << hrs << ":" << min << endl;
	}
private:
	int hrs;
	int min;
};

class Smart
{
public:
	Smart(Time* p) : ptr(p) {}
	~Smart()
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

void f(Smart& s)
{
	s->display();				// ptr = s.operator->()
	                        // ptr->hello()
	throw "problems";
}

int main()
{
	try
	{
		Smart s(new Time(2,15));
		f(s);
	} catch(const char* e) {
		cout << e << endl;
	}
}
