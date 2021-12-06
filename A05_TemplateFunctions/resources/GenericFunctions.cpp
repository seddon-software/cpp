////////////////////////////////////////////////////////////
//
//		Template Functions
//
////////////////////////////////////////////////////////////

#include <iostream>
//#include <string>

using namespace std;


int Max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

double Max(double a, double b)
{
	if (a > b)
		return a;
	else
		return b;
}

string Max(string a, string b)
{
	if (a > b)
		return a;
	else
		return b;
}

/////

/*
The compiler stores const items along with the program code in read only memory.
There are 4 main memory regions:

	Text Segment:		Code and const
	Data Segment:		Initialized and uninitialized global data and statics
	Heap:				data created at run time (managed by the programmer)
	Stack:				data created at compile time (managed by the compiler)

	The C strcmp function is used for char*.  It uses the ASCII code of the C-Strings.
	The CStrings are compared character by character until the strings differ. Since 
	the ASCII code for R (82) is greater than the ASCII code for B (66) the library
	concludes "Red" > "Blue".

	Note that the C_Strings are stored in the text segment, e.g.:

	Text:   0x45820000: start of program code
	        0x45828534: "Red"
			0x45828538: "Blue"
			...
*/
int main()
{
	cout << Max(5, 8) << endl;
	cout << Max(5.1, 8.3) << endl;
	cout << Max("Blue", "Red") << endl;	  // "Blue" is a const char* 
	cout << Max("Red", "Blue") << endl;
}

