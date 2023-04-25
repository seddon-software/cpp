/*
 *  When you write a class it is handy if you cant print the attributes with cout.  In order to do this 
 *  you need to overload the << operator.  This can be achieved by defining an operator<<() method.  Normally
 *  this would necessitate adding theis method to the class defining cout.  This turns out to be the library
 *  class "ostream".  However, this class can't be changed by the programmer because its a system library
 *  class.
 * 
 *  The workround is to write a free function.  Since you almost certainly need to use your class's private
 *  attributes in this function it needs to be declared as a friend.
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



