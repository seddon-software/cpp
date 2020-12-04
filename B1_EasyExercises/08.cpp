/*
 * Create two separate lists containing the integers from 10 to 19 and from 30 to 39.
 * How can you form a list that combines the two lists?
 */

#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> list1;
	list<int> list2;

	for(int i = 10; i <= 20; i++)
	{
		list1.push_back(i);
	}

	for(int i = 30; i <= 40; i++)
	{
		list2.push_back(i);
	}

	list<int> both(list1);
	both.merge(list2);

	for (auto item:both)
	{
		cout << item << ",";
	}
	cout << endl;
}
