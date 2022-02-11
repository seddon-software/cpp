///////////////////////////////////////////////////////
//
//       lookahead
//
///////////////////////////////////////////////////////

/*
 *  Here we investigate look ahead with RegEx to search for filenames that have an extension.  However,
 *  we want to exclude filenames with a ".bat" extension.  We also impose restrictions that the filename  
 *  must not be empty and that multiple dots in the filename are not allowed.
 * 
 *  The example sets up a series of tests in a vector of tuples.  Each tuple contains:
 *          a) test number
 *          b) filename being tested
 *          c) expected result (true or false)
 * 
 *  Hopefully all tests should pass.
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


void performTests(regex re, vector<tuple<int, string, bool>> tests)
{
    match_results<string::const_iterator> searcher;
	for(auto test:tests)
	{
		int testNumber = get<0>(test);
		string filename = get<1>(test);
		bool result = get<2>(test);
		bool found = regex_search(filename, searcher, re);

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

	regex re("\\w+[.](?!bat)\\w+$");
	performTests(re, tests);
}

