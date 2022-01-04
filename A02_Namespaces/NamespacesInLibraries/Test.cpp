////////////////////////////////////////////////////////////
//
//		Namespaces defined across multiple files
//
////////////////////////////////////////////////////////////

/* 
 *  This example is to show how a given namespaces can span multiple files
 *  The namespace "mylib" is split across 3 cpp files and one header file.
 * 
 *  If you are debugging this fom VSCode you will need to change configuration to:
 *      several C++ files
 *  to invoke the correct build and debug, since this example is based on several 
 *  files.  Don't forget to change back again to the configuration:
 *      C++ 
 *  to get all the single file examples to work.
 */

#include "MyLib.h"
using namespace mylib;

int main()
{
	f1();
	f2();
	f3();
	f4();
	f5();
	f6();
	f7();
	f8();
	f9();
}

