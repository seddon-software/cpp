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

