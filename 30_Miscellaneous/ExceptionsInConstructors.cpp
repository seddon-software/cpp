////////////////////////////////////////////////////////////
//
//		Exceptions in Constructors
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class String
{
public:
	String() {}

	String(const String* s)
	{
		cout << "String CTOR" << endl;
		if(!s) throw "String CTOR failed";
	}

	~String() 
	{
		cout << "String DTOR" << endl;
	}
};


class Date
{
public:
	Date() {}

	Date(const Date* d)
	{
		cout << "Date CTOR" << endl;
		if(!d) throw "Date CTOR failed";
	}

	~Date()
	{
		cout << "Date DTOR" << endl;
	}
};

class Person
{
public:
	Person(const String* n, const Date* d, bool valid) 
	: name(n), birthday(d) 
	{
		cout << "Person CTOR" << endl;
		if(!valid) throw "Person CTOR failed";
	}

	~Person()
	{
		cout << "Person DTOR" << endl;
	}
private:
	String name;
	Date   birthday;
};

/////

int main()
{
	String juliusCaesar;
	Date   bc100;

	try
	{
		//Person dictator(&juliusCaesar, &bc100, true); 
		//Person dictator(&juliusCaesar, &bc100, false); 
		//Person dictator(0, &bc100, true); 
		Person dictator(&juliusCaesar, 0, true); 
	}
	catch(const char* exception)
	{
		cerr << exception << endl;
	}

	return 0;
}
