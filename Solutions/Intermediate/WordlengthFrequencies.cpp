/********************************************************************
 *
 * Word lengths from /usr/share/dict/words
 *
 *******************************************************************/

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <map>
using namespace std;
#define WORD_LENGTH 120


#include <iostream>

using namespace std;

vector<string> readFile(const string& fileName)
{
    // build list containing the test data
	vector<string> v;

	ifstream in(fileName, ios::in);
	if (!in.is_open()) {
	    cerr << "failed to open " << fileName << endl;
	}

	for(string line; getline(in, line); )
	{
	    v.push_back(line);
	}

    return v;
}

map<int,int> calculateFrequencies(const vector<string>& words)
{
    map<int,int> frequencies;

    for (auto word : words)
    {
    	frequencies[word.size()]++;
    }
    return frequencies;
}

int main()
{
	auto words = readFile("/usr/share/dict/words");
	auto results = calculateFrequencies(words);

	for(auto t : results)
	{
		cout << get<0>(t) << ": " << get<1>(t) << endl;
	}
	cout << endl;
}
