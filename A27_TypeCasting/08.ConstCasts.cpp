#include <iostream>
using namespace std;

/*
 *  This example shows how to remove the constness of an object.  The author of the print function has
 *  forgotten to make it's parameter const.  That will mean we can't pass the array "c" as a parameter
 *  unless we use a const_cast.
 * 
 *  Obviously we need to add const to the function parameter.  However, if we have no access to this code
 *  to correct the mistake (e.g. in an external library), all we can do is the use the const_cast.  The 
 *  cast is easily spotted in the code and can be removed once the library code has been fixed.
 */

void print(char* str)
{
	cout << str << endl;
}

int main()
{
	char s[] = "text";
	const char c[] = "text";

	print(s);
	// print(c);   // doesn't compile
	print(const_cast<char *>(c));

}
