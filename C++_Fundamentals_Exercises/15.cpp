/*
 * Write a function that takes a vector of integers as a parameter
 * and doubles the value of each element, before returning the vector.
 */

#include <iostream>
#include <vector>
using namespace std;


vector<int> DoubleIt(vector<int> v)
{
	for(auto& i : v)
	{
		i *= 2;
	}
	return v;
}

int main()
{
	vector<int> myList = {2, 3, 5, 7, 11, 13, 17, 19};
	myList = DoubleIt(myList);
	for(auto i : myList)
	{
		cout << i << ",";
	}
	cout << endl;
}
