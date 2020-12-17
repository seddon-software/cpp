/*
 * Write a function that takes two int arrays (same size)
 * as parameters and adds the arrays together, element by
 * element.  Print out the array as part of the function.
 */

#include <iostream>
#include <vector>
using namespace std;


vector<int> AddArrays(const vector<int>& array1, const vector<int>& array2)
{
	int size = array1.size();
	vector<int> result(size);

	for(int i = 0; i < size; i++)
	{
		result[i] = array1[i] + array2[i];
	}
	return result;
}

int main()
{
	vector<int> a1 = {  3,  6,  9, 10, 20, 17, 14 };
	vector<int> a2 = { 17, 14, 11, 10,  0,  3,  6 };

	vector<int> a = AddArrays(a1, a2);

	for(auto i : a)
	{
		cout << i << ",";
	}
	cout << endl;
}
