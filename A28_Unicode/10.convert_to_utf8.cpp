#include <codecvt>
#include <string>
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>
//#include <cassert>
#include <bitset>
using namespace std;

/*
 *  Here we take a look at the UTF-8 encoding.  Recall that each Unicode character has a unique code point,
 *  the code point is not normally what is stored in memory.  Instead there are many possible encodings.  The
 *  UTF-8 encoding is the most populatr on the web (~75% of all websites use UTF-8).
 * 
 *  C++ has very limited support for encodings and the support it does have in <codecvt> has been deprecated
 *  in C++17.  Nevertheless, the support is unlikely to be replaced before 2030 and so it is safe to use
 *  the library for the next few years.
 * 
 *  There are numerous blogs on the web explaing how UTF-8 is related to the Unicode code point.  Here we print
 *  out both for some example Unicode characters:
 *  
 *    Character Code Point  UTF-8(hex) 	UTF-8(binary)
 *       $ 	    U+0024 	    24          00100100 	                            
 *       ¢ 	    U+00A2 	    C2 A2       11000010 10100010 	
 *       € 	    U+20AC 	    E2 82 AC    11100010 10000010 10101100
 *       𠂢     U+200A      F0 A0 82 A2 11110000 10100000 10000010 10100010  	            
 *       𤭢 	 U+24B62     F0 A4 AD A2 11110000 10100100 10101101 10100010 	
 */

void printChar32(const char32_t& c)
{
    wchar_t wstr[2] = {};
    wstr[0] = c;     
    // now convert to multibyte
    char mbstr[8] = {};
    int bytesConverted = wcstombs(mbstr, wstr, 8);
    if(bytesConverted != -1) cout << mbstr << ": " << flush;
}

void convert_to_UTF8(char32_t c32)
{
    // create converter object
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    // invoke to_bytes method
    std::string utf8string = converter.to_bytes(c32);

    // print results
    printChar32(c32);
    cout << setw(8) << hex << (int)c32 << ":\t " << flush;
    
    for(auto byte_ : utf8string)
    {
        int n = 24;
        cout << hex << (((unsigned int)(byte_)<<n)>>n) << " " << flush;
    }
    cout << setw(16) << " " << flush;
    for(auto byte_ : utf8string)
    {
        cout << hex << bitset<8>(byte_) << " " << flush;
    }
    cout << endl;
}

void headings()
{
    cout << "char code-point UTF8(hex)                 UTF8(binary)" << endl;
}

int main() 
{
    setlocale(LC_ALL, "");
    headings();
    convert_to_UTF8(0x0024);
    convert_to_UTF8(0x00A2);
    convert_to_UTF8(0x20AC);
    convert_to_UTF8(0x200A2);
    convert_to_UTF8(0x24B62);
}
