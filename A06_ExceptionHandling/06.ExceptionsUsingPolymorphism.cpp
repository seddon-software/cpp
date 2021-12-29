////////////////////////////////////////////////////////////
//
//	Exceptions using Inheritance
//
////////////////////////////////////////////////////////////

/*  An interesting method of catching exceptions is to use Polymorphism by creating
 *  multiple polymorphic handler methods.  In this example we define a base class with
 *  a pure virtual method called "diagnose".  All derived classes then implement this 
 *  method.  We can now catch base class objects by reference and use the V-Tables to 
 *  redirect to the correct polymorphic handler. 
 * 
 *  Note the use of private inheritance.  The V-Tables are a runtime mechanism and hence ignore
 *  the private specifier (which is enforced at compile time).
 */

#include <iostream>
#include <exception>
using namespace std;


struct Error : exception   // using private inheritance is OK
{
	virtual void diagnose() const = 0;
};

struct MathError : Error  // using private inheritance is OK
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
	catch(const Error& e)  // this catches Error, MathError or FileError
	{
		cout << "catching Error" << endl;
		e.diagnose();	// polymorphic call
	}

	try
	{
		throw FileError();
	}
	catch(const Error& e)  // this catches Error, MathError or FileError
	{
		cout << "catching Error" << endl;
		e.diagnose();	// polymorphic call
	}
}
