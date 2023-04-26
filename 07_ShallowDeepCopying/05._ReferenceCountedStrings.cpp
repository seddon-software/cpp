//////////////////////////////////////////////////////////////////////
//
//		Reference Counted Strings
//
//////////////////////////////////////////////////////////////////////

#include <cstring>

class string
{
public:
	string(const char* = "");
	string(const string&);
	~string();
	string& operator=(const string&);
private:
	class body;
	body* self;
};

class string::body
{
private:
	char*  text;
	size_t count;
public:
	body(const char*);
	~body();
	void Increment();
	void Decrement();
};

/////

string::body::body(const char* s)
{
	text = new char[strlen(s) + 1];
	strcpy(text, s);
	count = 1;
}

string::body::~body()
{
	delete [] text;
}

void string::body::Increment()
{
	count++;
}

void string::body::Decrement()
{
	count--;
	if (count == 0) delete this;
}

/////

string::string(const char* s)
{
	self = new body(s);
}

string::string(const string& s)
{
	self = s.self;
	self->Increment();
}

string& string::operator=(const string& s)
{
	if (this == &s) return *this;

	self->Decrement();	 // old string
	self = s.self;
	self->Increment();	 // new string
	return *this;	
}

string::~string()
{
	self->Decrement();
}

/////


int main()
{
	string s1("Blue");			// CTOR(const char*)
	string t1("Red");

	string s2(s1);				// copy CTOR
	string s3(s2);
	string t2(t1);

	t2 = t1 = s1;
}
  
