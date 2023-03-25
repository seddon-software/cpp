#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

/*  Sometimes exceptions are thrown from deeply nested routines (such as library calls) and the 
 *  catcher may not understand what the exception represents.  In such cases an intermediary can 
 *  intercept the exception and wrap it in a more understandable exception.  The catcher will 
 *  receive both errors.  In this example the library call creates the obscure exception and it 
 *  gets wrapped as a more understandable exception.
 */

// throws an exception nested in another:
void library_call()
{
	try
	{
		// this error may not be very informative to caller, so ...
		throw std::logic_error("obscure error");
	}
	catch (const std::exception& e)
	{
		// ... rethrow the exception wrapped in a more palatable error
		std::throw_with_nested(std::logic_error("understandable error"));
	}
}

int main()
{
	try
	{
		library_call();
	}
	catch (std::exception& e)
	{
		cerr << "unwrapped exception: " << e.what() << endl;
		try
		{
			std::rethrow_if_nested(e);
		}
		catch (const std::exception& e)
		{
			cerr << "wrapped exception: " << e.what() << endl;
		}
	}
}
