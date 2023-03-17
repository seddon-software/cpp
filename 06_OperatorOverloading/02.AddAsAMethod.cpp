////////////////////////////////////////////////////////////
//
//      Operator Overloading with member functions
//
////////////////////////////////////////////////////////////

/* 
 *  When overloading the + operator you have two choices: member function or free function.  In this example
 *  we show how to overload + as a member function.  However it is usually better to oveload as a free function
 *  since the free function is easily converted to a template and can be applied to several classes.  As a member
 *  function, the overload is tightly coupled to one class.
 * 
 *  The overload works because the compiler treats:
 *              t1 + t2
 *  
 *  as equivalent to writing:
 *              t1.operator+(t2)
 * 
 */

class Time
{
public:
    Time& operator+=(const Time& rhs)
    {
        *this = *this + rhs;
        return *this;
    }
    Time operator+(const Time& rhs) const;
    Time operator+(int rhs) const;
    friend Time operator+(int lhs, const Time& rhs);

    // default CTOR
    Time(): hrs(0), min(0) {}
    Time(int h, int m): hrs(h), min(m) {}
    Time(int m) : hrs(0), min(m) 
    {
        if(min > 60)
        {
            hrs = min / 60;
            min = min % 60;
        }
    }
    // copy CTOR
    Time(const Time& original): hrs(original.hrs), min(original.min) {}
    // DTOR
    ~Time() {}
    operator int()
    {
        return hrs * 60 + min;
    }
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
Time Time::operator+(int rhs) const  // *this is const
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
    t = t2 += t1;            // t = t.operator+=(t1)
    t = t1 + t2;		// t = t1.operator+(t2)
    t = t1 + 45;        // t = t1.operator+(7)
    t = 55 + t2;        // t = operator+(7, t1)
}

