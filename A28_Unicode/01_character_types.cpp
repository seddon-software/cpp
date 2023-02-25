/*
Unicode Support
===============

The Unicode standard defines several encoding formats, for example: UTF-8, UTF-16, and UTF-32. Each has advantages 
and disadvantages. Currently, C/C++ programmers use 
    char[] to encode UTF-8 strings, 
    wchar_t or wchar32_t for UTF-32
    UTF-32 is same as code point
    UTF-16 is not used any more in C++

C++ provides prefixes for string literals of the above types:
    u prefix for 16 bit code points (wchar16_t)
    U prefix for 32 bit code points (wchar32_t)

Notes: 
1. wchar_t is platform dependent (usually 32 bit on Linux, 16 bit on Windows)
2. there is NO library support (as yet) for char16_t and char32_t.

Check out these web sites:
    https://www.asciitable.com/
    https://symbl.cc/en/unicode/blocks/
    https://en.cppreference.com/w/
    https://www.cprogramming.com/tutorial/unicode.html
*/

#include <string>
#include <iostream>

#include <stdio.h>
#include <wchar.h>
#include <uchar.h>
#include <locale.h>
using namespace std;

int main(void)
{
    setlocale(LC_ALL, "");

    cout << "char has size " << sizeof(char) << endl;
    cout << "wchar_t has size " << sizeof(wchar_t) << endl;
    cout << "char16_t has size " << sizeof(char16_t) << endl;
    cout << "char32_t has size " << sizeof(char32_t) << endl;
}
