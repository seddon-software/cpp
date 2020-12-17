///////////////////////////////////////////////////////
//
//       lookahead
//
///////////////////////////////////////////////////////

/*
 *  Investigate look ahead with RegEx to search for filenames with an extension; the
 *  extension can be anything except ".bat".
 */


#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <regex>


using namespace std;

// Search criteria:
// 1) filenames with an extention
// 2) filename must not be empty
// 3) multiple dots in name not allowed
// 4) extension must not be .bat


void performTests(regex ex, vector<tuple<int, string, bool>> tests)
{
    match_results<string::const_iterator> searcher;
	for(auto test:tests)
	{
		int testNumber = get<0>(test);
		string text = get<1>(test);
		bool result = get<2>(test);
		bool found = regex_search(text, searcher, ex);

		if(found == result)
			cout << "test " << testNumber << " PASSED" << endl;
		else
			cout << "test " << testNumber << " FAILED" << endl;
	}
}

int main()
{
	// tests show true if valid filename and false otherwise
	vector<tuple<int, string, bool>> tests = {
		{ 1, "f1.txt",   true  },
		{ 2, "f2.",      false },		// no extension
		{ 3, "f3.bat",   false },		// can't have .bat extension
	    { 4, "f4,pdf",   false },
	    { 5, "f5..html", false },		// two dots
	    { 6, "f6..",     false },		// no extension
	    { 7, "f7.chm",   true  },
	    { 8, ".txt",     false },		// no filename
	    { 9, "f5.hbat",  true  },
	};

	regex filenameWithExtensionsThatAreNotDotBat("\\w+[.](?!bat)\\w+$");
	performTests(filenameWithExtensionsThatAreNotDotBat, tests);
}

