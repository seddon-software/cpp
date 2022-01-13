//////////////////////////////////////////////////////////////////////
//
//		Using set_new_handler
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 *  The set_new_handler function allows you to install a handler that is called whenever a memory 
 *  allocation attempt fails.
 */ 

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
    cout << "This program will grab a huge amount of memory" << endl
         << "your system may slow to a snails pace if you continue" << endl;
    string dummy;
    cout << "Hit return to continue of Ctrl-C to quit" << endl; 
    getline(cin, dummy);
	while(true)
	{
		new char[500 * MByte];
		MBytes += 500;
		cout << MBytes << " MBytes allocated" << endl;
	}
}
  
