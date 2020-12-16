#include <iostream>
using namespace std;



int a[6] = { 2, 3, 5, 7, 11, 13 };

int main()
{
	for(auto& x: a)
	{
		x = x * 10;
	}

	for(int i = 0; i < 6; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
