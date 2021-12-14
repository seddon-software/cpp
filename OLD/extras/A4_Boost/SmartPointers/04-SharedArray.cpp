////////////////////////////////////////////////////////////
//
//		Shared Array Pointers
//
////////////////////////////////////////////////////////////

#define BOOST_THREAD_USE_LIB
#include <iostream>
#include <string>

#include <boost/scope_exit.hpp>
#include <boost/shared_array.hpp>
using namespace std;


int main()
{
	boost::shared_array<int> array1(new int[5]);
	array1[0] = 100;
	array1[1] = 101;
	array1[2] = 102;
	array1[3] = 103;
	array1[4] = 104;

	boost::shared_array<int> array2(array1);
	array2[2] = 99;

	for(int i = 0; i < 5; i++)
	{
		cout << " " << array1[i];
	}
	cout << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << " " << array2[i];
	}
	cout << endl;

	return 0;
}

