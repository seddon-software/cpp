#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
using namespace std;
namespace fs = boost::filesystem;

int main()
{
	string filename("./FileSystem/03.FileProperties.cpp");
	fs::path cwd(".");
	cout << "Absolute path: " << fs::absolute(".") << endl;

	fs::path myfile(filename);

	if(!fs::exists(myfile))
	{
		std::cout << "not found: " << filename << std::endl;
		return 1;
	}

	if (!fs::is_regular_file(myfile))
	{
		std::cout << "not a regular file: " << filename << endl;
		return 1;
	}

	cout << "size of " << filename << " is " << fs::file_size(myfile) << endl;

	return 0;
}
