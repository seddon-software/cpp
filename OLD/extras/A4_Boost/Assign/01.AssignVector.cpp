////////////////////////////////////////////////////////////
//
//		Simple List
//
////////////////////////////////////////////////////////////

#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assert.hpp>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace boost::assign; // bring 'operator+=()' into scope

void Print(const int& i)
{
	cout << i;
	cout << endl;
}

int main()
{
    vector<int> values;  
    values += 1,2,3,4,5,6,7,8,9; // insert values at the end of the container

	for_each(values.begin(), values.end(), Print);
	return 0;
}
