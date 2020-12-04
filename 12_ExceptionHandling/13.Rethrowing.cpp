#include <iostream>
#include <exception>
using namespace std;

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
			throw;
		}
	}
	catch(exception& e)
	{
		 cout << e.what() << endl;
	}
}
