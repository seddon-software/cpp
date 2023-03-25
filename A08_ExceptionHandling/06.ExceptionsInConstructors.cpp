/*  
 *  CTORs may throw exceptions.  If a composite object throws, then DTORs are only called on the 
 *  parts that were constructed without throwing.  In this example we have a Person object consisting
 *  of two MyStrings and two Dates.  The example shows what happens when various CTORs throw.
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

bool trace = false;   // used to inhib unnecessary output

void print(const string& s)
{
	if(trace) cout << s << endl;
}

class MyString : public string
{
public:
    MyString(const string& s) : string(s)
    {
        print("MyString " + s + " constructed OK");
    }
    MyString(const MyString& rhs) : string(rhs)
    {
        if (*this == "" && ::trace)
        {
        	throw runtime_error("MyString Copy CTOR failed");
        }
        print("MyString " + rhs + " constructed OK");
    }
    ~MyString()
    {
        print("~MyString called");
    }
};

class Date
{
public:
    Date(int year) : year(year)
    {
        print("Date "s + to_string(year) + " constructed OK"s);
    }
    Date(const Date& rhs) : year(rhs.year)
    {
        if (year < 1950 && ::trace)
        {
        	throw runtime_error("Date Copy CTOR failed");
        }
        print("Date "s + to_string(rhs.year) + " constructed OK"s);
    }
    friend ostream& operator<<(ostream& out, const Date& d)
    {
        return out << d.year;
    }
    ~Date()
    {
        print("~Date called");
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
        if (!valid)
        {
            throw runtime_error("Person CTOR failed; DTOR not called");
        }
    }
    ~Person()
    {
        print("~Person called");
    }
private:
    MyString firstName;
    MyString lastName;
    Date   birthday;
    Date   deathday;
};

void createExceptionInPersonCTOR(const MyString& firstName, const MyString& lastName, const Date& born, const Date& died)
{
    cout << firstName << "," << lastName << "," << born << "," << died << endl;
    try
    {
        int valid = false;      // died before born
        ::trace = true;
        Person johnSmith(firstName, lastName, born, died, valid);
    }
    catch (const exception& e)
    {
        cout << endl << e.what() << endl;
        ::trace = false;
    }
}

// 
void createExceptionInStringCTOR(const MyString& firstName, const MyString& lastName, const Date& born, const Date& died)
{
    cout << firstName << "," << lastName << "," << born << "," << died << endl;
    try
    {
        ::trace = true;
        int valid = false;      // died before born
        Person johnSmith(firstName, lastName, born, died, valid);
    }
    catch (const exception& e)
    {
        cout << endl << e.what() << endl;
        ::trace = false;
    }
}

void createExceptionInDateCTOR(const MyString& firstName, const MyString& lastName, const Date& born, const Date& died)
{
    cout << firstName << "," << lastName << "," << born << "," << died << endl;
    ::trace = true;
    try
    {
        Person johnSmith(firstName, lastName, born, died, true);
    }
    catch (const exception& e)
    {
        cout << endl << e.what() << endl;
        ::trace = false;
    }
}

void createValidPerson(const MyString& firstName, const MyString& lastName, const Date& born, const Date& died)
{
    cout << firstName << "," << lastName << "," << born << "," << died << endl;
    ::trace = true;
    try
    {
        Person johnSmith(firstName, lastName, born, died, true);
        print("John Smith: no exceptions");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/////

int main()
{
	// exceptions are thrown in various CTORs
	// note that DTORs are only called (in reverse order) for objects fully constructed
    ::trace = false;
    MyString john("john");
    MyString smith("smith");
    MyString brown("brown");
    MyString blank("");
    Date _1937(1937);
    Date _2011(2011);
    Date _2062(2062);
    createValidPerson(john, smith, _2011, _2062);
    cout << "----------------" << endl;
    try 
    {
        createExceptionInPersonCTOR(john, brown, _2062, _2011);  // died before born
    } 
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
    cout << "----------------" << endl;
    try
    {
        createExceptionInStringCTOR(john, blank, _2011, _2062);  // illegal last name
    }
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
    cout << "----------------" << endl;
    try
    {
        createExceptionInDateCTOR(john, smith, _1937, _2062);    // born too early
    }
    catch(const runtime_error& e) 
    {
        cout << e.what() << endl;
    }
}
