//////////////////////////////////////////////////////////////////////
//
//		Reference Counted Strings
//
//////////////////////////////////////////////////////////////////////

#include <cstring>
#include <iostream>
using namespace std;

/* 
 *  The handle-body pattern can be used for reference counted strings.  In this example it seems 
 *  natural to add the reference counting to the body (unlike in the previous example).
 * 
 *  The example shows how to create a nested class:
 *      class String::body
 * 
 *  that is associated with the handle class:
 *      class String
 *  
 *  Note how the body has to be forward declared in the handle class:
 *      private:
 *          class body;  // forward declaration of nested class
 * 
 *  Asside from that the example is fairly similar to he previous example.
 * 
 *  When a handle-body pair goes out of scope we only need to decrement the reference count,
 *  leaving the body alone.  Except of course when the count becomes zero.  That's when the
 *  handle-body commits suicide!
 */

class String
{
public:
    friend ostream& operator<<(ostream& os, const String& s);
	String(const char* = "");
	String(const String&);
	~String();
	String& operator=(const String&);
private:
	class body;  // forward declaration of nested class
    friend ostream& operator<<(ostream& os, const body& s);
	body* pBody;
};

class String::body
{
friend ostream& operator<<(ostream& os, const String::body& s);
private:
	char*  text;
	size_t count;
public:
	body(const char*);
	~body();
	void Increment();
	void Decrement();
};

///// BODY

String::body::body(const char* s)
{
	text = new char[strlen(s) + 1];
	strcpy(text, s);
	count = 1;
}

String::body::~body()
{
	delete [] text;
}

void String::body::Increment()
{
	count++;
}

void String::body::Decrement()
{
	count--;
	if (count == 0) delete this;  // commit suicide
}

ostream& operator<<(ostream& os, const String::body& b)
{
     return os << "count = " << b.count << ", text = " << b.text << endl;   
}

///// HANDLE

String::String(const char* s)
{
	pBody = new body(s);
}

String::String(const String& s)
{
	pBody = s.pBody;
	pBody->Increment();
}

String& String::operator=(const String& s)
{
	if (this == &s) return *this;

	pBody->Decrement();	 // old String
	pBody = s.pBody;
	pBody->Increment();	 // new String
	return *this;	
}

String::~String()
{
	pBody->Decrement();
}

ostream& operator<<(ostream& os, const String& s)
{
    return os << *(s.pBody);
}

/////


int main()
{
	String s1("Blue");			// CTOR(const char*)
	String t1("Red");
    cout << s1 << t1 << endl;

	String s2(s1);				// copy CTOR
    cout << s2 << s1 << endl;

	String s3(s2);              // copy CTOR
    cout << s3 << s2 << s1 << endl;

	String t2(t1);              // copy CTOR
    cout << t2 << t1 << endl;

	t2 = t1 = s1;               // operator=()
    cout << s3 << s2 << s1 << t2 << t1 << endl;
}
  
