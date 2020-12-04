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


int main()
{
    array<int,7> a = {{2,3,5,7,11,13,17}};  // double {} should only be required for C++11

    // use the for each algorithm to double each item in the array
    for_each(a.begin(), a.end(), [](int& x) {
        x *= 2;
    });
    cout << endl;

    // print out the array
    for_each(a.begin(), a.end(), [](int x) {
        cout << x << ",";
    });
    cout << endl;

    // extract the array to variable and const pointers
    //int* p = a;				// error, no implicit conversion to int*
    __attribute__((unused))
    int* p = a.data(); 			// OK
    __attribute__((unused))
    const int* pc = a.data(); 	// OK
}

