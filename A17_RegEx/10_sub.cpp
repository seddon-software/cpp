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


string sub(const string& pattern, const string& replacement, const string& text)
{
	string newText(text);
	regex ex(pattern);
	regex_replace(ostreambuf_iterator<char>(cout), text.begin(), text.end(), ex, replacement);

	return newText;
}

int main()
{	string pattern = "\\s*([;:])\\s*";
	string text = "aaa  ; bbb :ccc     ;        ddd :  eee";
	string replacement = "--$1--";
	string newText = sub(pattern, replacement, text);
}

