#include <iostream>
#include <vector>
#include <stdexcept>

/*
 *  Using the [] to access a vector has the drawback that the index is not bounds checked.  However
 *  the at() method does the same thing, but supports bounds checking.
 */

using namespace std;

int main()
{
	vector v{2,3,5,7,11,13,17};

	cout << v[5] << endl;		// doesn't check for valid index
    cout << v.at(5) << endl;	// checks for valid index

    try
    {
        cout << v[55] << endl;    // doesn't throw (prints random number)
        cout << v.at(55) << endl; // does throw
    }
    catch(out_of_range& e)
    {
        cout << e.what() << endl;
    }
}
