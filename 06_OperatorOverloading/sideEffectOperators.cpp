////////////////////////////////////////////////////////////
//
//      Operator Overloading with member functions
//
////////////////////////////////////////////////////////////

class Time
{
public:
	Time& operator++();
	Time operator++(int);

    // default CTOR
    Time(): hrs(0), min(0) {}
    Time(int h, int m): hrs(h), min(m) {}
    // copy CTOR
    Time(const Time& original): hrs(original.hrs), min(original.min) {}
    // DTOR
    ~Time() {}
private:
    int hrs;
    int min;
};

// prefix
Time& Time::operator++()
{
	min++;
	if(min == 60)
	{
		min = 0;
		hrs++;
	}
    return *this;
}

// postfix
Time Time::operator++(int)
{
	// take snapshot
	Time snapshot(*this);
	++(*this);
    return snapshot;
}

int main()
{
    Time t;
    Time t1(4, 30);
    Time t2(3, 15);

    t = t1++;		// t = t1.operator++(0);
    t = ++t2;		// t = t2.operator++();
}

