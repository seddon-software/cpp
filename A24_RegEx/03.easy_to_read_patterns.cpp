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
 *  C++ allows strings to be concatenated and this in turn allows us to put comments in the RegEx.
 *  Note the subpattern:
 *          "(.*?)"
 * 
 *  This is an example of non greedy matching.  The .* matches 0 or more (any) characters, but the ? says
 *  match as few characters as possible.  There a 3 sets of capture parentheses in the full RegEx and 
 *  hence there are 3 results, stored in searcher[1], searcher[2] and searcher[3].
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


