////////////////////////////////////////////////////////////
//
//      Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Time
{
public:
    friend Time operator+(int lhs, const Time& rhs);

    Time(): hrs(0), min(0) {}       // default CTOR
    // conversion CTOR
    Time(int m): hrs(0), min(m) 
    {
        if(min >= 60)
        {
            hrs = min / 60;
            min = min % 60;
        }
    }  
    operator int() const;                 // cast operator
    Time(int h, int m): hrs(h), min(m) {}
    // copy CTOR
    Time(const Time& original): hrs(original.hrs), min(original.min) {}
    // DTOR
    ~Time() {}
private:
    int hrs;
    int min;
};


Time::operator int() const
{
    return hrs * 60 + min;
}


int main()
{
    Time t;
    Time t1(4, 30);
    Time t2(3, 15);
    int y1 = (int)t1;  // explicit conversion
    int y2 = t2;       // implicit conversion
    t = (Time)100;     // explicit conversion
    t = 110;           // implicit conversion
}

