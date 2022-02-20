// Tutorial on filesystem: 
//		https://www.bfilipek.com/2017/08/cpp17-details-filesystem.html

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
// gcc has not added filesystem head to the library as of version 9.2.0
// so use the following instead
#include <experimental/filesystem>
// note we must also link with LFLAGS = -lstdc++fs

using namespace std;
namespace fs = std::experimental::filesystem;


bool search_for_string(const fs::path & pfound, const string& word)
{
	ifstream inputFile(pfound);

	// in the following the extra set of brackets are necessary because of
	// C++ most vexing parse.  Refer to:
	//		https://www.fluentcpp.com/2018/01/30/most-vexing-parse/
	string dataFromFile((istreambuf_iterator<char>(inputFile)),
					    istreambuf_iterator<char>());
	inputFile.close();

	size_t n = dataFromFile.find(word); // returns -1 (string::npos) on failure

	if(n != string::npos)
		return true;
	else
		return false;
}

vector<fs::path> findFiles(const fs::path& root, const string& ext)
{
	vector<fs::path> result;

	// check root is valid
	if (!exists(root) || !is_directory(root)) return result;

	// setup iterators
	fs::directory_iterator iter(root), end_iter;

	while(iter != end_iter)
	{
		if (is_directory(*iter))
		{
			// recurse if *iter is a directory
			vector<fs::path> r = findFiles(*iter, ext);
			// add paths to result
			result.insert(result.end(), r.begin(), r.end());
		}
		else
		{
			// check if file extension matches
			if(fs::path(*iter).extension() == ext) result.push_back(*iter);
		}
		++iter;
	}
	return result;
}

int main()
{
	string textToFind = "Magic";
	string extension = ".txt";
	fs::path root_path("resources");
	vector<fs::path> result = findFiles(root_path, extension);

//	for(unsigned i = 0; i < result.size(); i++)
	for(auto r : result)
	{
		bool found = search_for_string(r, textToFind);
		if(found)
		{
			cout << "Found: " << textToFind << " in file: "
				 << r << endl;
		}
	}
}
