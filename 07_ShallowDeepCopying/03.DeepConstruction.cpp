/*
 *  To overcome the problems with shallow construction we need to write a copy constructor.  This 
 *  constructor must ensure the original and the copy object have separate heap storage.  By duplicating 
 *  the heap storage we avoid double deallocation.
 */

#include <cstdio>
#include <cstring>

using namespace std;

class String
{
private:
    char* text;
public:
    String(const char* = "");
    String(const String&);    // Copy CTOR
    ~String();
};

/////

String::String(const char* theString)
{
    text = new char [strlen(theString) + 1];
    strcpy(text, theString);
}

String::String(const String& theString)
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
}
