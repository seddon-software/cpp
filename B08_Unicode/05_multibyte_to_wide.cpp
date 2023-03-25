#include <iostream>
#include <iomanip>
#include <clocale>
#include <cwchar>
#include <string>
#include <cstring>      // for memset
using namespace std;

/*
 *  In this example we convert from wide characters to multi-byte strings.
 */

void convert_to_wide_and_print(const wstring& name, const char* multiByteStr)
{
    mbstate_t state;
    memset(&state, 0, sizeof state);   // zero the state
    size_t length = 1 + mbsrtowcs(NULL, &multiByteStr, 0, &state);  // state gets set by the call
    wchar_t wideStr[length];
    int size = mbsrtowcs(&wideStr[0], &multiByteStr, length, &state);
    wcout << setw(12) << left << name << L": " << wideStr;
    wcout << L", size: " << size << endl;
}

int main(void)
{
    setlocale(LC_ALL, "");
    
    // work directly with unicode characters
    convert_to_wide_and_print(L"star", "★");
    convert_to_wide_and_print(L"pi", "π");
    convert_to_wide_and_print(L"hebrew alef", "א");
    convert_to_wide_and_print(L"pài", "𠂢");
    convert_to_wide_and_print(L"russian letters", "АБВГДЕЖЗИЙКЛ");

    // work with code points
    convert_to_wide_and_print(L"star", "\u2605");
    convert_to_wide_and_print(L"pi", "\u03C0");
    convert_to_wide_and_print(L"hebrew alef", "\u05D0");
    convert_to_wide_and_print(L"pài", "\U000200A2");
    convert_to_wide_and_print(L"russian letters", "\u0410\u0411\u0412\u0413\u0414\u0415"
                                                  "\u0416\u0417\u0418\u0419\u041A\u041B");
}
