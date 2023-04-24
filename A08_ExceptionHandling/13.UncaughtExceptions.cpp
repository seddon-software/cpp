/*  If you fail to catch an exception the program will terminate.  You can install a handler to
 *  catch this scenario.  This is useful on an older code base that doesn't catch all exceptions
 *  and it is difficult to pinpoint where the exception occurs.
 * 
 *  See https://panthema.net/2008/0901-stacktrace-demangled/ for info on stack traces with g++.
 */

#include <iostream>
#include <exception>
#include <execinfo.h>  // for backtrace
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

   // storage array for stack trace address data
    void* addrlist[64];

    // retrieve current stack addresses
    int size = backtrace(addrlist, sizeof(addrlist) / sizeof(void*));

    // resolve addresses into strings containing "filename(function+address)",
    // this array must be free()-ed
    char** symbolList = backtrace_symbols(addrlist, size);

    cout << "-------- stack trace follows --------" << endl;
	for(int i = 0; i < size; i++)
	    cout << symbolList[i] << endl;

	free(symbolList);
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
