////////////////////////////////////////////////////////////
//
//    Regular Expressions
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

/*
 *  As we've seen from the last example, searching is more flexible than matching.  In this simple example
 *  we are searching for a number in a string.
 * 
 *  Note the RegEx is "\\d+[.]\\d+".  This means one or more digits followed by a literal dot and terminated 
 *  by one or more digits.
 */

using namespace std;

void search(const string& text, const string& pattern)
{
    match_results<string::const_iterator> searcher;
    regex ex(pattern);
	bool found = regex_search(text, searcher, ex);

	if(found)
		cout << "Pattern found in <" << text << ">: " << searcher[0] << endl;
	else
	    cout << "Pattern NOT found in <" << text << ">" << endl;
}

int main()
{
    string text1("This line contains the number 8.73 and 4.67");
    string text2("This line does not contains any numbers");
    string numberPattern("\\d+[.]\\d+");

	search(text1, numberPattern);
	search(text2, numberPattern);
}
