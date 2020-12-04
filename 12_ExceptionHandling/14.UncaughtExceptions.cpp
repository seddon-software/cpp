#include <iostream>
#include <exception>
#include <cstdlib>
using namespace std;

struct MyException : public exception
{
    const char* what() const noexcept
    {
    	cout << "what() called ..." << endl;
        return  "MyException";
    }
};

void terminator()
{
	cout << "terminate handler called" << endl;
	exit(1);
}

int main()
{
	set_terminate(terminator);
	try
	{
		throw MyException();
	}
	catch(range_error& e)
	{
		cout << "range error ..." << endl;
	}
}
