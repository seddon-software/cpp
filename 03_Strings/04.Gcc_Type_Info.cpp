/*  
 *  Here's a typical example of using the char* type.
 *   
 *  C++11 introduced many new featues to the language including type inference.  It is no
 *  longer necessary to explicitly declare variable if the compiler already knows about the type.
 *  You can use "auto" and "declspec" to get the compiler to work out your types.
 * 
 *  Unfortunately its difficult to see the types chosen by the compiler, because the compiler 
 *  mangles symbols.  However since we are exclusively using g++ we can make use of the specific
 *  gcc routine to demangle names shown below.  This will not work with other compilers.
 */

#include <iostream>
#include <functional>
#include <typeinfo>
#include <cxxabi.h>    // gcc specific header to demangle names

using namespace std;

// this routine only works with gcc.  Note the extra include file <cxxabi.h> and changes to the Makefile.
const char* demangle(auto p)
{
	int status;  // did the demangle work?
	const char* realname = abi::__cxa_demangle(typeid(p).name(),0,0,&status);  // gcc specific code (see Makefile)
	return realname;
}

int f(int a, int b)
{
    return a + b;
}

int main()
{
	// complicated function pointer
	auto fp = &f;			// int (*fp)(int, int) = &f;

    // use typeid to print the type of fp (unfortunately it's mangled by the compiler)
    cout << "type of fp: " << typeid(fp).name() << endl;
	
    // use the demangle function to print type of fp 
	cout << "type of fp: " << demangle(fp) << endl;
}
