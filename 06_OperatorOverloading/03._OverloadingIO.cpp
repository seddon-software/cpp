/*
 *
 */

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
    Time(int h, int m): hrs(h), min(m) {}
    // friend functions can access private members
    // they have no this pointer
    friend ostream& operator<<(ostream& os, const Time& t)
    {
        os << "Hours = "   << t.hrs << ", "
        << "Minutes = " << t.min;

        return os;
    }
private:
    int hrs;
    int min;
};

// prototype
ostream& operator<<(ostream& os, const Time& t);

/////

int main()
{
    Time t(6, 12);
    cout << t       // operator<<(cout, t);
         << endl;
}



