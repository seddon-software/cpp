////////////////////////////////////////////////////////////
//
//      Arrays
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

/*
 *  Now we a templated vector class it seems a natural extension to provide a fixed size vector
 *  that doesn't dynamically resize (for effeciency).  Such a class is called array.  Note at the end 
 *  of the example we show how to convert array to the equivalent C construct.
 */

int main()
{
    array<int,7> theArray = {2,3,5,7,11,13,17};  // the size is the second template parameter

    // double each item in the array
    for(auto& i : theArray)
    {
        i *= 2;
    };

    // print out the array
    for(auto i : theArray)
    {
        cout << i << ", ";
    };
    cout << endl;

    // extract the array to variable and const pointers
    //int* p = theArray;				// error, no implicit conversion to int*
    __attribute__((unused))
    int* p = theArray.data(); 			// OK
    __attribute__((unused))
    const int* pc = theArray.data(); 	// OK
}

