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

using namespace std;

/*  
 *  Here we explore the difference between greedy and non-greedy matching.  The greedy pattern is:
 *	            "^(.+)(\\d+)(.+)$"
 *
 *  and the non-greedy pattern is the same with a ? added:
 *              "^(.+?)(\\d+)(.+)$"
 *
 *  The key part of the pattern is the first bracketed sub-pattern.  For the greedy pattern
 *              "(.+)"
 *  we match as many (any) characters as we can, but the characters must follow start of line (because 
 *  of ^) and must preceed one or more digits (\\d+).  Of all the possible matches, the search engine
 *  chooses the one that matches the most characters in the first part of the (greedy) pattern.  This 
 *  part matches:
 *              AAAA1111BBBB2222CCCC333
 *  as this does follow the start of line and does proceed at least on digit (3).  
 * 
 *  With the non-greedy matching, the characters must also follow start of line and must preceed one 
 *  or more digits (\\d+), but this time the first sub-pattern has to be minimal:
 *              AAAA
 *  Note this part is at the start of line, preceeds 1 or more digits and is the minimal such pattern.
 */


void test(const string& name, const string& pattern)
{
    match_results<string::const_iterator> searcher;
    regex ex(pattern);
    string text("AAAA1111BBBB2222CCCC3333DDDD");
	regex_search(text, searcher, ex);
	cout << name << "<" << searcher[1] <<
	               "><" << searcher[2] <<
	               "><" << searcher[3] << ">" << endl;
}

int main()
{
	test("Greedy:     ", "^(.+)(\\d+)(.+)$");
	test("Non-Greedy: ", "^(.+?)(\\d+)(.+)$");
}

