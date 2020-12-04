////////////////////////////////////////////////////////////
//
//      Problems with Shallow Copy Constructor
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

class String
{
private:
    char* text;
public:
    // no Copy CTOR defined
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

void f(String theString)    // parameter passed by copy
{
}

int main()
{
    String s("Blue");

    f(s);
}
