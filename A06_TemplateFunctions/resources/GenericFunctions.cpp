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
	
	Note that when we use a template, the template parameter T will be of type const char*.
	This, in turn, means the template will compare pointers rather than the C-Strings. So, if
	the C-Strings are as above, then the templated Max function:
			template <typename T>
			T Max(T a, T b)
			{
				if (a > b)
			    	return a;
				else
				    return b;
			}
	when a is "Red" and b is "Blue" will translate to:
			if (0x45828534 > 0x45828538)
				return 0x45828534;
			else
				return 0x45828538
	when the parameters are the other way round will translate to: 
			if (0x45828538 > 0x45828534)
				return 0x45828538;
			else
				return 0x45828534
	Both cases return the larger address, namely 0x45828538 and not necessarily the greater 
	C-String.  It depends which string is stored in the higher memory location and not on the 
	content of the C-String, which is obviously incorrect.  That means the template won't work.
	We'll need to find a work around!	  
*/
int main()
{
	cout << Max(5, 8) << endl;
	cout << Max(5.1, 8.3) << endl;
	cout << Max("Blue", "Red") << endl;	  // "Blue" and "Red" are of type = const char* 
	cout << Max("Red", "Blue") << endl;
}

