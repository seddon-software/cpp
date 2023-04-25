/*
 *  Casts are used to convert one type of object into another.  C++ used a single parameter Time constructor
 *  to create Time objects from an int (minutes):
 *              Time(int m): hrs(0), min(m)
 *              {
 *                  // code ...
 *              }
 * 
 *  and operator int to convert in the other direction:
 *              operator int() const
 *              {
 *                  // code
 *              }
 * 
 *  Note the odd placement of const in the cast method.  This implies *this is const in this function
 *  (i.e. *this won't be modified in this method). 
 */

#include <iostream>
using namespace std;

class Time
{
public:
    friend Time operator+(int lhs, const Time& rhs);

    Time(): hrs(0), min(0) {}       // default CTOR
    // cast (conversion) CTOR: min -> Time
    Time(int m): hrs(0), min(m) 
    {
        if(min >= 60)
        {
            hrs = min / 60;
            min = min % 60;
        }
    }
    // cast operator: Time -> min
    operator int() const         // const => *this is read only        
    {
        return hrs * 60 + min;
    }
    Time(int h, int m): hrs(h), min(m) {}
    Time(const Time& original): hrs(original.hrs), min(original.min) {} // copy CTOR
    ~Time() {} // DTOR
private:
    int hrs;
    int min;
};



int main()
{
    Time t;
    Time t1(4, 30);
    Time t2(3, 15);
    [[maybe_unused]]
    int y1 = (int)t1;  // explicit conversion
    [[maybe_unused]]
    int y2 = t2;       // implicit conversion
    t = (Time)100;     // explicit conversion
    t = 110;           // implicit conversion
}

