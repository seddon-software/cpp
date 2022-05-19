/*
 *  
 */

#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>
#include <cxxabi.h>    // gcc specific header to demangle names

/*  
 */

using namespace std;


// this routine only works with gcc.  Note the extra include file <cxxabi.h> and changes to the Makefile.
const char* demangle(auto p)
{
	int status;  // did the demangle work?
	const char* realname = abi::__cxa_demangle(typeid(p).name(),0,0,&status);  // gcc specific code (see Makefile)
	return realname;
}

int main()
{
	vector v = {100, 200};
    list l = {100, 200};
    auto vi = v.begin();
    auto li = l.begin();
	cout << "type of vi: " << demangle(vi) << endl;
	cout << "type of li: " << demangle(li) << endl;
}
