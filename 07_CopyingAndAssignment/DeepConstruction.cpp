////////////////////////////////////////////////////////////
//
//      Deep Copy Constructors
//
////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

class String
{
private:
    char* text;
public:
    String(const char* = "");
    String(String&);    // Copy CTOR
    ~String();
};

/////

String::String(const char* theString)
{
    text = new char [strlen(theString) + 1];
    strcpy(text, theString);
}

String::String(String& theString)
{
    (*this).text = new char [strlen(theString.text) + 1];
    strcpy(text, theString.text);
}

String::~String()
{
    delete [] text;
}

/////

int main()
{
    String s1("Blue");
    String s2(s1);

    return 0;
}
