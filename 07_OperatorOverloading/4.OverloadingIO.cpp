////////////////////////////////////////////////////////////
//
//      Operator Overloading to support IO
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Time
{
public:
    Time()
    :
        hrs(0),
        min(0)
    {
    }
    Time(int h, int m)
    :
        hrs(h),
        min(m)
    {
    }
    int GetHours()   const { return hrs; }
    int GetMinutes() const { return min; }
private:
    int hrs;
    int min;
};

// prototype
ostream& operator<<(ostream& os, const Time& t);

// global function (not a friend!!)
ostream& operator<<(ostream& os, const Time& t)
{
    os << "Hours = "   << t.GetHours()
       << "Minutes = " << t.GetMinutes();

    return os;
}

/////

int main()
{
    Time t(6, 12);

    cout << t       // operator<<(cout, t);
         << endl;
}



