/*
 *  Templates come in two varieties: class and function templates.  Here is a very simple template called
 *  Max (uppercase M because the standard library has a function called max).  This template takes a 
 *  typename T as a parameter; Max takes two T parameters of the same type.
 *   
 *  Templates with different types are also allowed (see later examples).  T can take on any valid type; 
 *  in this example T takes on the types int, double and const char*.  Using an single uppercase letter to
 *  denote type is a common convension used in C++.
 * 
 *  Note that "Red" and "Blue" are char arrays and the compiler designates their type as: const char*,
 *  which is a pointer type.  This turns out to be a problem for our template because the template will 
 *  compare the pointers and not their contents.  Since const char* arrays are constant, the compiler 
 *  stores these const items along with the program code in read only memory (text segment).
 *  
 *  There are 4 main memory regions:
 * 
 *      Text Segment:       Code and const
 *      Data Segment:       Initialized and uninitialized global data and statics
 *      Heap:               data created at run time (managed by the programmer)
 *      Stack:              data created at compile time (managed by the compiler)
 * 
 *  The two char arrays will appear in memory something like the following:
 * 
 *      Text Segment:   0x45820000: start of program code
 *                                  ... (more code)
 *                                  ... (start of constants)
 *                      0x45828538: "Red"
 *                      0x4582853C: "Blue"
 *                                  ... (end of constants)
 *
 *  When the template compares the two pointers it will always decide "Blue" is greater, because
 *  it has a higher memory address.
 */

#include <iostream>
#include <string>

using namespace std;



// note with T=const char* this template will compare pointers
template <typename T>
T Max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

/////

int main()
{
    // call the template with T = int
	cout << Max(5, 8) << endl;

    // call the template with T = double
	cout << Max(5.1, 8.3) << endl;

    // call the template with T = string
	cout << Max(string("Blue"), string("Red")) << endl;

    // call the template with T = const char*
	cout << Max("Blue", "Red") << endl;     // compares pointers
	cout << Max("Red", "Blue") << endl;	

    // print out the pointers    
    cout << "\"Blue\" is stored at: " << (void*)"Blue" << endl;
    cout << "\"Red\"  is stored at: " << (void*)"Red" << endl;
}

