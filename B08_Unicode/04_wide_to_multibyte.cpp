#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
using namespace std;

/*
 *  The functions mbstowcs() and wcstombs() convert between multibyte and wide charaters.  Multi-byte 
 *  characters strings are variable length.  For interest sake we print the length of the mult-byte
 *  string upon conversion.   
 */

void convert_to_multibyte_and_print(const string& name, const wchar_t* wstr)
{
    char mbstr[32] = {};
    // now convert to multibyte
    int bytesConverted = wcstombs(mbstr, wstr, 32);
    cout << setw(14) << left << name << ": " << mbstr;
    cout << ", size = " << bytesConverted << endl;
}

int main() 
{
    setlocale(LC_ALL, "");
    // work directly with unicode characters
    convert_to_multibyte_and_print("star", L"★");
    convert_to_multibyte_and_print("pi", L"π");
    convert_to_multibyte_and_print("hebrew alef", L"א");
    convert_to_multibyte_and_print("pài", L"𠂢");
    convert_to_multibyte_and_print("russian letters", L"АБВГДЕЖЗИЙКЛ");

    // work with code points
    convert_to_multibyte_and_print("star", L"\u2605");
    convert_to_multibyte_and_print("pi", L"\u03C0");
    convert_to_multibyte_and_print("hebrew alef", L"\u05D0");
    convert_to_multibyte_and_print("pài", L"\U000200A2");
    convert_to_multibyte_and_print("russian letters", L"\u0410\u0411\u0412\u0413\u0414\u0415"
                                                       "\u0416\u0417\u0418\u0419\u041A\u041B");
}
 
