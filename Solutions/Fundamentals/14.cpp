/*
 * Write a function that takes a string and capitalises the first character of the string and ensures the remaining characters are converted to lower case.  Use the following test data:
 *     UpperFirst("test1")
 *     UpperFirst("mIxEdCaSe")
 *     UpperFirst("UPPER")
 *     UpperFirst("lower")
 *     UpperFirst("oPPOSITE")
 */

#include <iostream>
#include <string>
using namespace std;

string UpperFirst(string s)
{
	s[0] = toupper(s[0]);
	return s;
}

int main()
{
    cout << UpperFirst("test1") << endl;
	cout << UpperFirst("mIxEdCaSe") << endl;
	cout << UpperFirst("UPPER") << endl;
	cout << UpperFirst("lower") << endl;
	cout << UpperFirst("oPPOSITE") << endl;
}
