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
 *  RegEx's can have multiple capture parentheses.  This example has nested captures.
 *  Recall that capture 0 represents the full match of the RegEx.
 */

using namespace std;


int main()
{
    match_results<string::const_iterator> searcher;
	string text = "AAAA1111BBBB2222CCCC";

	regex ex(
		"^("           // capture-1
		  "("          // capture-2
		   "(\\D+)"    // capture-3
		   "(\\d+)"    // capture-4
		  ")"
		  "("          // capture-5
		   "(\\D+)"    // capture-6
		   "(\\d+)"    // capture-7
		  ")"
		 "(\\D+)"      // capture-8
		")$"
	);

	regex_search(text, searcher, ex);

	for(auto it = searcher.begin(); it != searcher.end(); ++it)
	{
		unsigned index = it - searcher.begin();
		cout << index << ": " << *it << endl;
	}
}


