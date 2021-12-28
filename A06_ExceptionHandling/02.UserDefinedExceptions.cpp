#include <iostream>
#include <string>
#include <exception>
using namespace std;

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
