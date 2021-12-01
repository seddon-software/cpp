////////////////////////////////////////////////////////////
//
//      Operator Overloading with member functions
//
////////////////////////////////////////////////////////////

class Time
{
public:
    Time operator+(const Time& rhs) const;
    Time operator+(int rhs) const;
    friend Time operator+(int lhs, const Time& rhs);

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


Time Time::operator+(const Time& rhs) const
{
    Time result;
    result.hrs = (*this).hrs + rhs.hrs;
    result.min = (*this).min + rhs.min;
    if(result.min >= 60) 
    {
        result.min -= 60;
        result.hrs++;
    }
    return result;
}
Time Time::operator+(int rhs) const
{
    Time result;
    result.hrs = (*this).hrs;
    result.min = (*this).min + rhs;
    if(result.min >= 60) 
    {
        result.min -= 60;
        result.hrs++;
    }
    return result;
}

Time operator+(int lhs, const Time& rhs)
{
    return rhs + lhs;
}

int main()
{
    Time t;
    Time t1(4, 30);
    Time t2(3, 15);

    t = t1 + t2;		// t = t1.operator+(t2)
    t = t1 + 45;        // t = t1.operator+(7)
    t = 55 + t2;        // t = operator+(7, t1)
}

