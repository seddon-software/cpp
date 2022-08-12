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
    // getters and setters effectively make hrs and min public!
    int getHours()   const { return hrs; }
    int getMinutes() const { return min; }
private:
    int hrs;
    int min;
};

// prototype
ostream& operator<<(ostream& os, const Time& t);

// global function because it never accesses private members (not a friend!!)
ostream& operator<<(ostream& os, const Time& t)
{
    os << "Hours = "   << t.getHours() << ", "
       << "Minutes = " << t.getMinutes();

    return os;
}

/////

int main()
{
    Time t(6, 12);
    cout << t       // operator<<(cout, t);
         << endl;
}



