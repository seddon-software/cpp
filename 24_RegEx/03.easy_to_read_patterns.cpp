//////////////////////////////////////////////////
//
//   Advanced pattern matching ...
//
//////////////////////////////////////////////////

#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

/*
 *  C++ allows strings to be concatenated and this in turn allows us to
 *  put comments in the RegEx.
 *  This example also explores non greedy matching.
 */

using namespace std;


int main()
{
    match_results<string::const_iterator> searcher;
	string text = "AAAA1111BBBB2222CCCC3333DDDD";
	regex ex(
		 "^"        // start of line
		 "(.*?)"    // 0 or more characters
				    // non greedy
		 "(\\d+)"   // 1 or more digits
		 "(.*)"     // 0 or more characters
		 "$"        // end of line
	   );
	bool found = regex_search(text, searcher, ex);

	if(found && (searcher.size() == 4))
	{
		cout << searcher.size() << endl;
		cout << "Part1: " << searcher[1] << endl;
		cout << "Part2: " << searcher[2] << endl;
		cout << "Part3: " << searcher[3] << endl;
	}
}


