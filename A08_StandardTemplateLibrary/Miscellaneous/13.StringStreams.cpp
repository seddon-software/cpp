#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <cstring>

using namespace std;

int main( )
{
	string myString("hello");
	char myCString[] = "goodbye";
	int myInt = 127;

	stringstream ss;
	// write to it
	ss << myInt << "," << myString << "," << myCString;
	cout << ss.str() << endl;

	// reset variables
	myString = "";
	myInt = 0;

	// read from it ...
	//    ... an easy way to convert strings of digits into ints, floats or doubles
	char comma;
	ss >> myInt >> comma >> myString;  // myString consumes the rest of the string

	cout << myString << comma << myInt << endl;
}
