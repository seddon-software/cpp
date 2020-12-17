#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
using namespace std;


int main()
{
	// use an O/S independent file specification
	{
		boost::filesystem::path myDirectory("./FileSystem");
		bool result = boost::filesystem::is_directory(myDirectory);
		std::cout << "Path is a directory : " << std::boolalpha << result << endl;
	}
	{
		boost::filesystem::path myFile("./FileSystem/02.OsIndependentFileNames.exe");
		bool result = boost::filesystem::is_directory(myFile);
		std::cout << "Path is a file : " << std::boolalpha << result << endl;
	}
}
