///////////////////////////////////////////////////////
//
//  split
//
///////////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

using namespace std;

vector<string> split(string s, const string& pattern) {
	// s gets modified
	regex e(pattern);
	regex_token_iterator<string::iterator> i(s.begin(), s.end(), e, -1);
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

	result = split("hello-to-you", "-");
	for(auto word:result) cout << word << ",";
	cout << endl;

    string text = "  aaa  ; bbb ;ccc     ;    ^    ddd ;  eee   ";
	result = split(trim(text), "[\\s^;]+");
	for(auto word:result) cout << word << ",";
	cout << endl;
}

