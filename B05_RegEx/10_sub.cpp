///////////////////////////////////////////////////////
//
//       substitute
//
///////////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/*  
 *  This example modifies a string based on the complex delimiters:
 *              "\\s*([;:])\\s*"
 * 
 * The delimeter pattern is 0 or more spaces followd by a semi-colon or colon followed by 0 or more spaces.
 * The pattern also uses capture parentheses around the semi-colon or colon.  This enables us to use part of
 * the original delimiter in the replacement pattern:
 *              "-$1-"
 * The $1 is the first capture (the semi-colon or colon).  Thus we replace the complete delimiter with
 * either
 *              -:- or -;-
 * depending on whether we detected a semi-colon or a colon in the original delimeter.
 */

string sub(const string& pattern, const string& replacement, const string& text)
{
	string newText(text);
	regex re(pattern);
	return regex_replace(text, re, replacement);
}

int main()
{	
    string pattern = "\\s*([;:])\\s*";
	string text = "the  ; quick :brown     ;        fox :  jumped  ;  over    ; the:  lazy :dog";
	string replacement = "-$1-";
	string newText = sub(pattern, replacement, text);
    cout << "Original Text: " << text << endl;
    cout << "New Text:      " << newText << endl;
}

