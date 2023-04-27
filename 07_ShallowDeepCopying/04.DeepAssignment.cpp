/*
 *  The assignment problem can be resolved by providing an overloaded assignment operator.  The standard
 *  says this must be a member function and not a free function.
 * 
 *  This example shows how to write an overloaded assignment operator that performs a deep
 *  assignment.  Before any assignment is attempted, it is wise to check that the client is not attempting to 
 *  copy an object to itself. This is easily achieved:
 *              if (this == &object) return object;
 *
 *  The text pointer must be handled carefully: the original heap space is first deleted:
 *              delete [ ] text;
 * 
 *  and then a new area of the heap allocated:
 *              text = new char [strlen(object.text)];
 * 
 *  Finally, this storage is initialized:
 *              strcpy(text, object.text);
 * 
 *  Note that the object used on the right hand side of the assignment is input to the function as a reference 
 *  and returned from the function as a reference. This is more efficient than using copies. It also means 
 * that the object's constructor is not called!
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
