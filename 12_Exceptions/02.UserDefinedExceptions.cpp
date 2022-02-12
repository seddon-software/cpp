#include <iostream>
#include <string>
#include <exception>
using namespace std;

/*
 *  You can use any type with exception handling from built in types such as int, double, const char* 
 *  on the one hand to objects defined by classes.  Modern practice is to use the std library class, 
 *  exception or a class derived from exception.
 * 
 *  The standard library provides a number of exception classes you can use or you can define your own.
 *  In this example we define our own exception class derived from the standard exception class.
 * 
 *  The standard exception class provides a virtual method for passing error messages:
 *      exception::what() 
 * 
 *  and we need to override this method in our derived class.  Note the signature of the virtul method
 *  should match that in the base class (or at least be covariant).
 */

struct MyException : public exception
{
	MyException(string message):message(message) {}
    virtual const char* what() const noexcept		// note the signiture (defined by exception)
    {
        return message.c_str();
    }
	const string message;
};

int main()
{
	try
	{
	    throw MyException("oops");
	}
	catch(const MyException& e)
	{
	     cout << "MyException caught" << endl;
	     cout << e.what() << endl;
	}
}
