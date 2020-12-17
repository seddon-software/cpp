////////////////////////////////////////////////////////////
//
//		Smart Pointers
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;


class TimeBody
{
private:
	int hours;
	int minutes;
public:
	TimeBody(int h, int m) : hours(h), minutes(m) 
	{
		cout << "CTOR called" << endl;
	}

	~TimeBody() 
	{
		cout << "DTOR called" << endl;
	}
	
	void Print() const
	{ 
		cout << hours << ":" << minutes << endl; 
	}

    void BadBoy()
    {
        throw "BadBoy called ...";
    }
};

/////

class Time
{
public:
	Time() : ptr(0)
	{}

	Time(int h, int m) : ptr(new TimeBody(h,m))
	{}

	~Time()
	{
		delete ptr;
	}

	TimeBody* operator->()
	{
		if (ptr == 0) throw "pointer is null";
		return ptr;
	}

	void operator=(TimeBody* const p)
	{
		ptr = p;
	}

private:
	TimeBody* ptr;
};

/////
class myVector : public vector<Time*>
{
public:
    ~myVector()
    {
        myVector& list(*this);

        for(unsigned i = 0; i < list.size(); i++)
        {
            delete list[i];
        }
    }
};

int main()
{
	try
	{
        myVector list;
        list.push_back(new Time(1, 15));
        list.push_back(new Time(2, 30));
        list.push_back(new Time(3, 45));

        for(unsigned i = 0; i < list.size(); i++)
        {
            Time& t = *list[i];
            t->Print();
        }
        (*list[0])->BadBoy();
    }
	catch(const char* message)
	{
		cout << message << endl;
	}
}

