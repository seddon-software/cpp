/*
Unicode Support

The Unicode standard defines several encoding formats, for example: UTF-8, UTF-16, and UTF-32. Each has advantages 
and disadvantages. Currently, C/C++ programmers use 
    char[] to encode UTF-8 strings, 
    wchar_t or wchar32_t for UTF-32
    UTF-32 is same as code point
    UTF-16 is not used any more

C++ provides prefixes for string literals of these new types:
    u prefix for 16 bit code points (wchar16_t)
    U prefix for 32 bit code points (wchar32_t)

Notes: 
1. wchar_t is platform dependent (usually 32 bit on Linux, 16 bit on Windows)
2. there is NO library support (as yet) for char16_t and char32_t.

Check out these web sites:
    https://www.asciitable.com/
    https://unicode-table.com/en/
    https://en.cppreference.com/w/
    https://www.cprogramming.com/tutorial/unicode.html
*/

#include <string>
#include <iostream>
#include <cxxabi.h>    // gcc specific header to demangle names
using namespace std::string_literals; // enables s-suffix for std::string literals
using namespace std;

// this routine only works with gcc.  Note the extra include file <cxxabi.h> and changes to the Makefile.
const char* demangle(auto p)
{
	int status;  // did the demangle work?
	const char* realname = abi::__cxa_demangle(typeid(p).name(),0,0,&status);  // gcc specific code (see Makefile)
	return realname;
}

void print(const string& s, auto x)
{
    cout << s << ": " << demangle(x) << "  size: " << sizeof(x) << endl;
}

int main(void)
{
    // R"(...") is a raw string
    print(R"('A')", 'A');
    print(R"(L'A')", L'A');
    print(R"(u8'A')", u8'A');
    print(R"(u'A')", u'A');
    print(R"(U'A')", U'A');

    print(R"('Б')", 'Б');        // multibyte constant is of type int
    print(R"(L'Б')", L'Б');
//    print(R"(u8'Б')", u8'Б');  // char8_t too small
    print(R"(u'Б')", u'Б');
    print(R"(U'Б')", U'Б');
    cout << hex << (int)U'Б' << endl; 
}
