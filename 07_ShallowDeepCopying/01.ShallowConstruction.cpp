/*
 *  In this example we write our own string class to illustrate potential problems with copying certain 
 *  objects.  This class contains subtle bugs.  Of course, in practice we would use the string class in 
 *  the standard library rather write our own.
 *  
 *  Objects of this string class are of variable size.  Notice that they have a single attribute:
 *              char* text;
 * 
 *  In the const char* constructor this pointer is set to point at the heap where the character data
 *  is stored:
 *              text = new char [strlen(theString) + 1];
 *              strcpy(text, theString);
 * 
 *  Note the +1 to allow for a null terminator when allocating space on the heap for the character array.
 *  All this code is perfectly reasonable.  Problems arise in the main program when we call f().  We pass
 *  "s" to this function, but the function parameter is passed by value and therefore a copy is produced.
 *  This copy needs to be initialised by the copy constructor, but we haven't written one.  In this case
 *  the compiler provides one automatically.  Unfortunately the compiler's copy constructor doesn't work
 *  because it doen't know about the characters on the heap.  So it only copies the attibutes declared in
 *  the class: 
 *              char* text;
 * 
 *  This means the copy and the original are sharing heap space.  When the original and the copy are cleaned
 *  up in their respective destructors they both deallocate the heap space.  Double deallocation of heap 
 *  space will corrupt the heap and the program usually crashes.
 */

#include <stdio.h>
#include <string.h>

using namespace std;

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
