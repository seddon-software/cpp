#include <iostream>
using namespace std;

/*
 *	if statements can now havean initialization clause
 */


int main()
{
	int y = 50;
	if(int x = 100; x > y)
		cout << "x > y" << endl;
}
