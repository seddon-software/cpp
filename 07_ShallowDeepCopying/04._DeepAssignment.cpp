////////////////////////////////////////////////////////////
//
//      Deep Assignment
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
	 String(const String&);    // Copy CTOR
	 String& operator=(const String&);
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
    text = new char [strlen(theString.text) + 1];
    strcpy(text, theString.text);
}

String& String::operator=(const String& theString)
{
    if (this == &theString) return *this;  // check if objects the same

    delete [] text;                               // clean up object
    text = new char [strlen(theString.text) + 1]; // allocate new space
    strcpy(text, theString.text);                 // copy data

    return *this;
}

String::~String()
{
    delete [] text;
}

/////

int main()
{
	 String s1("Blue");
	 String s2("Red");

	 s1 = s2;
}
