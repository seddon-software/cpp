#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception
{
    virtual const char* what() const noexcept
    {
        return "my message";
    }
};

int main()
{
	try
	{
	    throw MyException();
	}
	catch(MyException& e)
	{
	     cout << "MyException caught" << endl;
	     cout << e.what() << endl;
	}
	catch(exception& e)
	{
	     // Other errors
	}
}
