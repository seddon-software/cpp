#include <iostream>
using namespace std;



int main()
{
	unsigned long long x = 1;

	for(int i = 0; i < 64; i++)
	{
		cout << i << ":" << x << endl;
		x = x * 2;
	}

	return 0;
}
