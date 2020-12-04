//////////////////////////////////////////////////////////////////////
//
//		Using set_new_handler
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <cstdlib>
#include <iostream>
using namespace std;

enum { MByte = 1024 * 1024 };  

void low_on_memory()
{
	cout << "No more memory" << endl;
	exit(1);
}

/////

int main()
{
	int MBytes = 0;
	set_new_handler(low_on_memory);

	while(true)
	{
		new char[5 * MByte];
		MBytes += 5;
		cout << MBytes << " MBytes allocated" << endl;
	}

	return 0;
}
  
