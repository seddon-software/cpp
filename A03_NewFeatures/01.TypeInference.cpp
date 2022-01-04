#include <iostream>
#include <functional>
#include <typeinfo>
#include <cxxabi.h>    // gcc specific header to demangle names

/*  C++11 introduced many new featues to the language including type inference.  It is no
 *  longer necessary to explicitly declare variable if the compiler already knows about the type.
 *  You can use "auto" and "declspec" to get the compiler to work out your types.
 * 
 *  Unfortunately its difficult to see the types chosen by the compiler, because the compiler 
 *  managles symbols.  However since we are exclusively using g++ we can make use of the specific
 *  gcc routine to demangle names shown below.  This will not work with other compilers.
 */

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
	int x = 100;
	// define a variable with the same type as x
	decltype(x) y = x;
	cout << "type of y: " << demangle(y) << endl;
	
	// if you are not too sure of a type, let the compile figure it out for you
	using namespace std::placeholders;
	auto functionPointer = bind(&f, _1, _2);  // bind: see later in the course
	cout << "type of functionPointer: " << demangle(functionPointer) << endl;
	int result = functionPointer(x, y);
	cout << result << endl;

	// complicated function pointer
	auto fp = &f;			// int (*fp)(int, int) = &f;
	cout << "type of fp: " << demangle(fp) << endl;
	result = fp(10, 20);
	cout << result << endl;

	// try a lambda
	auto fp2 = [](int a, int b){return a + b;};
	cout << "type of lambda: " << demangle(fp2) << endl;
}
