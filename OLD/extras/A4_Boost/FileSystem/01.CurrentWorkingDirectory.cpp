#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
using namespace std;
namespace fs = boost::filesystem;

int main()
{
	fs::path myPath(".");

	cout << "Absolute path: " << fs::absolute(".") << endl;
	cout << "Canonical path: " << fs::canonical(".") << endl;
	cout << "Absolute path: " << fs::absolute(myPath) << endl;
	return 0;
}
