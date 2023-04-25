/*
 *  In this example we write our own string class to illustrate potential problems with copying these objects.  
 *  This class contains subtle bugs.  Of course, in practice we would use the string class in  the standard 
 *  library rather than this class.
 *  
 *  Objects of this string class are of variable size.  Notice that they have a single attribute:
 *              private:
 *                  char* text;
 *  In the const char* constructor this pointer is set to point at the heap where the character data
 *  is stored:
 *              text = new char [strlen(theString) + 1];
 *              strcpy(text, theString);
 * 
 *  Note the +1 to allow for a null terminator when allocating space on the heap for the character array.
 *  TO BE COMPLETED

 * 
 *  In the main   
 */
////////////////////////////////////////////////////////////
//
//      Problems with Shallow Copy
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
