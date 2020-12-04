#include <iostream>
#include <exception>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
using namespace std;

int main()
{
	fs::path f1("./FileSystem/temp/f1");
	fs::path f2("./FileSystem/temp/f2");

	try
	{
		fs::rename(f1, f2);
		cout << f1 << " renamed" << endl;
	}
	catch (fs::filesystem_error& e)
	{
		cout << e.what() << endl;
		cout << "Can't rename " << f1 << endl;
	}

}
