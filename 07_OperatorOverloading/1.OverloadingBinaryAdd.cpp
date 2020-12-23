////////////////////////////////////////////////////////////
//
//      Operator Overloading with member functions
//
////////////////////////////////////////////////////////////

class Time
{
public:
    Time operator+(const Time& y) const;

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


Time Time::operator+(const Time& y) const
{
    Time result;
    result.hrs = (*this).hrs + y.hrs;
    result.min = (*this).min + y.min;

    return result;
}

int main()
{
    Time t;
    Time t1(4, 30);
    Time t2(3, 15);

    t = t1 + t2;		// t = t1.operator+(t2);
}

