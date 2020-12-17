#include <iostream>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
using namespace std;

//Search for a file with the name <filename> starting in directory <dir_path>,
// copy the path of the file in <pfound> if found, and return true.
// otherwise return false.

bool find_file(const fs::path & dir_path,
		       const std::string & file_name,
		       fs::path & pfound)
{
	if (!exists(dir_path) || !is_directory(dir_path)) return false;
	fs::directory_iterator iter(dir_path), end_iter;

	while(iter != end_iter)
	{
		if (is_directory(*iter))
		{
			if (find_file(*iter, file_name, pfound))
				return true;
		}
		else if (iter->path().filename() == file_name)
		{
			pfound = *iter;
			return true;
		}
		++iter;
	}
	return false;
}


void find(string root, string filename)
{
	fs::path pfound;
	try
	{
		if(find_file(root, filename, pfound))
			cout << "File: " << filename << " found in " << root << endl;
		else
			cout << "File: " << filename << " NOT found in " << root << endl;
	}
	catch (const fs::filesystem_error& e)
	{
		cout << "Error: " << e.what() << endl;
	}

}

int main()
{
	find("..", "07.Searching.cpp");
	find("..", "07.Searching.zzz");
}
