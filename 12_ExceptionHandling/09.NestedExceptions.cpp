#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

// throws an exception nested in another:
void library_call()
{
	try
	{
		// this error may not be very informative to caller, so ...
		throw std::logic_error("library error");
	}
	catch (const std::exception& e)
	{
		// rethrow the exception wrapped in a more palatable error
		std::throw_with_nested(std::logic_error("business error"));
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
