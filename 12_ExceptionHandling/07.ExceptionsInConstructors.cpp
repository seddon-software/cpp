////////////////////////////////////////////////////////////
//
//		Exceptions in Constructors
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

bool trace = false;

void print(const string& s)
{
	if(trace) cout << s << ", ";
}

class MyString : public string
{
public:
    MyString(const string& s) : string(s)
    {
        print("MyString");
    }
    MyString(const MyString& rhs) : string(rhs)
    {
        if (*this == "" && ::trace)
        {
        	cout << "exception" << endl;
        	throw runtime_error("MyString CTOR failed");
        }
        print("MyStringCC");
    }
    ~MyString()
    {
        print("~MyString");
    }
};

class Date
{
public:
    Date(int year) : year(year)
    {
        print("Date");
    }
    Date(const Date& rhs) : year(rhs.year)
    {
        if (year < 1950 && ::trace)
        {
        	cout << "exception" << endl;
        	throw runtime_error("Date CTOR failed");
        }
        print("DateCC");
    }
    ~Date()
    {
        print("~Date");
    }
private:
    int year;
};

class Person
{
public:
    Person(const MyString& first, const MyString& last, const Date& birth, const Date& death, bool valid)
        : firstName(first), lastName(last), birthday(birth), deathday(death)
    {
        cout << "Person, ";
        if (!valid)
        {
            cout << endl << "exception" << endl;
            throw runtime_error("Person CTOR failed");
        }
    }
    ~Person()
    {
        cout << "~Person, ";
    }
private:
    MyString firstName;
    MyString lastName;
    Date   birthday;
    Date   deathday;
};

void exceptionInPersonCTOR()
{
    ::trace = false;
    MyString john("john");
    MyString smith("smith");
    Date _1987(1987);
    Date _2011(2011);
    ::trace = true;
    cout << endl;
    cout << "exception in Person CTOR" << endl;
    cout << "========================" << endl;
    try
    {
        Person johnSmith(john, smith, _1987, _2011, false);
    }
    catch (const exception& e)
    {
        cout << endl << e.what() << endl;
        ::trace = false;
    }
}

void exceptionInStringCTOR()
{
    ::trace = false;
    MyString john("john");
    MyString empty("");
    Date _1987(1987);
    Date _2011(2011);
    ::trace = true;
    cout << endl;
    cout << "exception in String CTOR" << endl;
    cout << "========================" << endl;
    try
    {
        Person johnSmith(john, empty, 1987, 2011, false);
    }
    catch (const exception& e)
    {
        cout << endl << e.what() << endl;
        ::trace = false;
    }
}

void exceptionInDateCTOR()
{
    ::trace = false;
    MyString john("john");
    MyString smith("smith");
    Date _1937(1937);
    Date _2011(2011);
    ::trace = true;
    cout << endl;
    cout << "exception in Date CTOR" << endl;
    cout << "======================" << endl;
    try
    {
        Person johnSmith(john, smith, _1937, _2011, false);
    }
    catch (const exception& e)
    {
        cout << endl << e.what() << endl;
        ::trace = false;
    }
}

/////

int main()
{
	// exceptions are thrown in various CTORs
	// note that DTORs are only called (in reverse order) for objects fully constructed
    exceptionInPersonCTOR();
    exceptionInStringCTOR();
    exceptionInDateCTOR();
}
