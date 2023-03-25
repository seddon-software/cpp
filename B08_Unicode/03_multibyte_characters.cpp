// The functions mbstowcs() and wcstombs() convert from and to locale-specific encodings, respectively.

#include <iostream>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
using namespace std;

/*
 *  As an alternative to wide mode you can use narrow mode; narrow mode uses multi-byte characters.  When 
 *  working with multi-byte characters you can't print them a character at a time with cout (not wcout)
 *  because all the overloaded operator<< templates are marked deleted for individual characters.  However, 
 *  if you place the characters into a null terminated multi-byte string then you will be able to print.
 * 
 *  In this example we print multi-byte strings with cout (they use ""), but not multi-byte characters 
 *  (they use '').  You will notice you can print the Unicode characters themseves or use their code point 
 *  values.  I've copied the Unicode characters from the following website:
 *              https://symbl.cc/en/unicode/blocks/
 * 
 *  When working with code points you use the u and U prefixes.  For example, for 16 bit code points:
 *              const char* star2 = "\u2605"
 *  and for 32 bit code points:
 *              const char* pài2 = "\U000200A2";
 */

int main() 
{
    // define multi-byte string with unicode character
    const char* star1 = "★";
    cout << star1 << endl;
    // same, but using code point value
    const char* star2 = "\u2605";
    cout << star2 << endl;
    // note: multi-byte constants need to be unsigned, but won't print properly anyway
    unsigned int star3 = '★';
    cout << star3 << endl;  // this doesn't work

    // define multi-byte string with unicode character in higher code point range
    const char* pài1 = "𠂢";
    cout << pài1 << endl;
    // same, but using code point value
    const char* pài2 = "\U000200A2";
    cout << pài2 << endl;
}
 
