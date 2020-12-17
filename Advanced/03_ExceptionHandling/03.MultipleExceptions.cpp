#include <iostream>
#include <exception>
using namespace std;

struct MyExceptionA : exception {};
struct MyExceptionB : exception {};
struct MyExceptionC : exception {};

int main()
{
	try
	{
	    throw MyExceptionA();
	}
	catch(MyExceptionA& e) { cout << "A" << endl; }
	catch(MyExceptionB& e) { cout << "B" << endl; }
	catch(MyExceptionC& e) { cout << "C" << endl; }

	try
	{
	    throw MyExceptionB();
	}
	catch(MyExceptionA& e) { cout << "A" << endl; }
	catch(MyExceptionB& e) { cout << "B" << endl; }
	catch(MyExceptionC& e) { cout << "C" << endl; }

	try
	{
	    throw MyExceptionC();
	}
	catch(MyExceptionA& e) { cout << "A" << endl; }
	catch(MyExceptionB& e) { cout << "B" << endl; }
	catch(MyExceptionC& e) { cout << "C" << endl; }
}
