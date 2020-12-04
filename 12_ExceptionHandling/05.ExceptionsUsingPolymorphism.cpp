////////////////////////////////////////////////////////////
//
//	Exceptions using Inheritance
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


struct Error
{
	virtual void diagnose() const = 0;
};

struct MathError : Error
{
	virtual void diagnose() const { cout << "MathError" << endl; }
};

struct FileError : Error
{
	virtual void diagnose() const { cout << "FileError" << endl; }
};

/////

int main()
{
	try
	{
		throw MathError();
	}
	catch(const Error& e)
	{
		cout << "catching Error" << endl;
		e.diagnose();	// polymorphic call
	}

	try
	{
		throw FileError();
	}
	catch(const Error& e)
	{
		cout << "catching Error" << endl;
		e.diagnose();	// polymorphic call
	}
	return 0;
}
