/*
 * Composition is where an object is made up of other child objects.
 * Unlike Aggregation, the child objects cannot exist independently of the parent.
 * So in this example the person has a name, birthday and height which only make
 * sense when they are part of another object (Person).
 */

#include <string>
using namespace std;


class Date
{
public:
    Date(int, int, int);
    Date(const Date&);
private:
    int day;
    int month;
    int year;
};

/////

class Person
{
public:
    Person(const string&, const Date&, double);
private:
    string name;        // component
    Date   birthday;    // component
    double height;
};

/////

Date::Date(int d, int m, int y)
:
    day  (d),
    month(m),
    year (y)
{
}

Date::Date(const Date& anotherDate)
:
    day  (anotherDate.day),
    month(anotherDate.month),
    year (anotherDate.year)
{
}


Person::Person(const string& theName, const Date& theDate, double theHeight)
:
	 name    (theName),
	 birthday(theDate),
	 height  (theHeight)
{
}


/////

int main()
{
     Date   _1_Mar_100bc(1,  3, -100);
	 Person juliusCaesar("Julius Caesar", _1_Mar_100bc, 1.79);
}


