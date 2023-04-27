/*
 *  When assignment is attempted between two of our String objects, the compiler will always perform a 
 *  shallow assignment of the objects unless you provide an overloaded assignment operator function.
 *
 *  Here we call the function g() and it returns a String object by value which is then assigned to "s":
 *           	String s("Blue");
 *           	s = g();
 *
 *  With shallow assignment, as with shallow copying, the two objects share the same heap storage. We have 
 *  the same disastrous situation: when either object's destructor is called the other object's heap space 
 *  gets deallocated!
 * 
 *  All this gives rise to the Rule of 3: with objects like String that allocate resources on the heap you
 *  can't rely on the compiler generated methods and you have to provide 3 customised routines:
 *              String(const String&)               // copy constructor
 *              String& operator=(const String&)    // assignment operator
 *              ~String()                           // destructor
 * 
 *  Things became more complicated with the advent of move semantics with C++11 and now you need additional
 *  move contructors and move assignment operators as well (see advanced course).
 */

#include <cstdio>
#include <cstring>

using namespace std;


class String
{
private:
    char* text;
public:
    // Copy CTOR not defined
    // operator= not overloaded
    String(const char* = "");
    ~String();
};

/////

String::String(const char* theString)
{
    text = new char [strlen(theString) + 1];
    strcpy(text, theString);
}

String::~String()
{
    delete [] text;
}

/////

String g()
{
	 String temp("Green");
	 return temp;
}

int main()
{
	 String s("Blue");
	 s = g();
}
