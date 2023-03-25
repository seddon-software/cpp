#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <regex>

/*
 *  RegEx's can have multiple capture parentheses.  This example has nested captures.  Recall that 
 *  capture 0 represents the full match of the RegEx.  The matches object overloads the [] operator
 *  to make it easy to extract the results of each capture parenthesis of which (including nesting)
 *  there are 8 distinct results.
 */

using namespace std;


int main()
{
    match_results<string::const_iterator> matches;
	string text = "AAAA1111BBBB2222CCCC";

	regex re(
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

	regex_search(text, matches, re);
    for (size_t i = 0; i < matches.size(); ++i) 
        cout << i << ": " << matches[i] << endl;
}


