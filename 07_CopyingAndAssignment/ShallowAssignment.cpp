////////////////////////////////////////////////////////////
//
//      Problems with Shallow Assignment
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

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
