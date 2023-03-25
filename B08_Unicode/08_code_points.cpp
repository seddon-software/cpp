#include <iostream>
#include <iomanip>
#include <cwchar>
#include <cuchar>
#include <clocale>
#include <cstdlib>
#include <cstddef>
#include <unistd.h>
using namespace std;

/*
 *  A Unicode character can be represented by a char32_t or wchar_t.  When we wish to print such characters we can
 *  choose to print as wide or narrow characters.  Note that char32_t is inheritanly wide and can't be printed as 
 *  a narrow character, only its code point value can be printed.  Therefore the standards committee have marked 
 *  all the overloads of operator<< for char32_t as being deleted.  However, we can place the character in a 
 *  narrow string (when it can be printed with cout).
 * 
 *  No such problem exists in wide mode; we can print our UTF-8 encoded character using wcout.
 */

mbstate_t ss;    /* set shift state to the initial state */

void print_narrow_info()
{
    char32_t pài = U'𠂢';
    cout << "size of char32_t: " << sizeof(char32_t) << endl;
    // the standards commitee have marked all the operator<< functions for char16_t, char32_t as deleted
    // so we can't print these characters directly, but we can be print them as part of a string
    cout << "code point of 𠂢: " << hex << (unsigned long)pài << endl;
}
void print_wide_info()
{
    wchar_t pài = L'𠂢';
    wcout << L"size of wchar_t: " << sizeof(wchar_t) << endl;
    wcout << L"code point of 𠂢: " << hex << (unsigned long)pài << endl; 
}

int main(void)
{
    setlocale(LC_ALL, "");

    // recall you can only use wide or narrow streams, so comment out one of the next two calls
    // print_narrow_info();
    print_wide_info();
}
