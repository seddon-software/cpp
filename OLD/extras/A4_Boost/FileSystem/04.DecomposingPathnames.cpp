#include <iostream>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
using namespace std;

int main()
{
	// decompose the current path into its constituent directories
	fs::path path1(".");
	fs::path path2(fs::canonical(path1));	// convert to canonical representation first
	fs::path::iterator fsiterator = path2.begin();
	while (fsiterator != path2.end()) {
		std::cout << *fsiterator << std::endl;
		++fsiterator;
	}
}


