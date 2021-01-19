#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <unordered_map>

using namespace std;

struct Functor
{
	bool operator() (const pair<string,int>& p1,const pair<string,int>& p2)
	{
		if(p1.second > p2.second)
			return false;
		else
			return true;
	}
};

void getMaxStem(std::vector<std::string> v, unsigned length)
{
	// create a hash for stems
	unordered_map<string, int> stems;

	// build up the stems with an associated count
	for(unsigned i = 0; i < v.size(); i++)
    {
    	if(v[i].size() >= length)
    	{
			string stem = v[i].substr(0, length);
			stems[stem]++;
    	}
    }

	// find stem with highest count
    Functor functor;		// functor to do the comparison
    auto iterator = max_element(stems.begin(), stems.end(), functor);
    cout << "Most popular stem of size " << length << ": "
    	 << iterator->first << "(occurs " << iterator->second << " times)" << endl;
}

int main()
{
	// open file
	ifstream inputFile("resources/allwords.txt");

	// read into a vector
	std::vector<std::string> v;
	std::copy(std::istream_iterator<std::string>(inputFile),
	          std::istream_iterator<std::string>(),
	          std::back_inserter(v));

	// loop for all stem lengths
	for(int i = 2; i <= 20; i++)
	{
		getMaxStem(v, i);
	}
}

