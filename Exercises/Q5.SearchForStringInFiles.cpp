#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
using namespace std;



bool search_for_string(fs::path & pfound, const string& word)
{
	string filename= boost::filesystem::canonical(pfound).string();
	ifstream inputFile(filename);

	// istreambuf_iterator uses low level routine to read every character
	string dataFromFile((istreambuf_iterator<char>(inputFile)),
					    istreambuf_iterator<char>());
	inputFile.close();

	size_t n = dataFromFile.find(word);
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
			// recurse
			vector<fs::path> r = findFiles(*iter, ext);
			// add paths to result
			result.insert(result.end(), r.begin(), r.end());
		}
		else
		{
			// check file extension matches
			if(fs::extension(*iter) == ext)	result.push_back(*iter);
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

	for(unsigned i = 0; i < result.size(); i++)
	{
		bool found = search_for_string(result[i], textToFind);
		if(found)
		{
			cout << "Found: " << textToFind << " in file: "
				 << boost::filesystem::canonical(result[i]).string() << endl;
		}
	}
}
