#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
	vector<int> v = {2,3,5,7,11,13};

	cout << v[5] << endl;		// doesn't check for valid index
    cout << v.at(5) << endl;	// checks for valid index

    try
    {
        cout << v[55] << endl;
        cout << v.at(55) << endl;
    }
    catch(out_of_range& e)
    {
        cout << e.what() << endl;
    }
}
