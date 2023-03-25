#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

using namespace std;

/*
 *  This time we split a space separated string of words into a vector using 
 *  regex_token_iterator<string::iterator>.  However we only need to keep the prefixes and not the 
 *  matches in this case, so the submatch flag is set to -1.
 * 
 *  As a further example, we show how to split a string with a complex delimeter: the delimeter can
 *  be any combination of spaces, semi-colons or hat symbols as defined by the RegEx:
 *                  [\\s^;]+
 */

vector<string> split(string s, const string& pattern) {
	// s gets modified
	regex re(pattern);
	regex_token_iterator<string::iterator> i(s.begin(), s.end(), re, -1);
	regex_token_iterator<string::iterator> end;	// default CTOR creates end of sequence
	vector<string> matches;
	while (i != end)
	{
		matches.push_back(*i);
		i++;
	}
	return matches;
}

string trim(string& s)
{
	s.erase(0, s.find_first_not_of(" \n\r\t"));
	s.erase(s.find_last_not_of(" \n\r\t")+1);
	return s;
}

int main()
{
	vector<string> result;

	result = split("The quick brown fox jumped over the lazy dog", " ");
	for(auto word:result) 
        cout << word << ",";
	cout << endl;

    string text = "  aaa  ; bbb ;ccc     ;    ^    ddd ;  eee   ";
	result = split(trim(text), "[\\s^;]+");
	for(auto word:result) 
        cout << word << ",";
	cout << endl;
}

