#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

int main( )
{
	string myString("hello");
	char myCString[] = "hello";
	int myInt = 127;

	stringstream ss;
	// write to it
	ss << myInt << myString << myCString;
	cout << ss.str() << endl;

	// reset variables
	myString = "";
	strcpy(myCString, "");
	myInt = 0;

	// read from it
	ss >> myInt >> myString;
	// also an easy way to convert strings of digits into ints, floats or doubles

	cout << myString << myInt << endl;
}
