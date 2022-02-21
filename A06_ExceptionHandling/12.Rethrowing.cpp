#include <iostream>
#include <exception>
using namespace std;

/*  
 *  Good practice is to log errors and then rethrow.  This example just simulates logging.  For real 
 *  logging consult third party libraries.
 */

struct MyException : public exception
{
    const char* what() const noexcept
    {
        return "MyException thrown";
    }
};

int main()
{
	try
	{
		try
		{
			throw MyException();
		}
		catch(...)
		{
			cout << "logging error ..." << endl;
			throw;   // rethrow after exception is logged
		}
	}
	catch(exception& e)
	{
		 cout << e.what() << endl;
	}
}
