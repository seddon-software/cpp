#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
using namespace std;
namespace fs = boost::filesystem;

void CheckEquivalence(const fs::path& lhs, const fs::path& rhs)
{
	if(fs::equivalent(lhs, rhs))
		cout << "equivalent paths: " << endl
	         << "\t" << lhs << endl
		     << "\t" << rhs << endl;
	else
		cout << "NOT equivalent paths: " << endl
			 << "\t" << fs::canonical(lhs) << endl
			 << "\t" << fs::canonical(rhs) << endl;
}

int main()
{
	fs::path p1("FileSystem/01.CurrentWorkingDirectory.cpp");
	fs::path p2("../15-Boost/FileSystem/01.CurrentWorkingDirectory.cpp");
	fs::path p3("FileSystem/../FileSystem/01.CurrentWorkingDirectory.cpp");
	fs::path q1("FileSystem/01.CurrentWorkingDirectory.exe");
	CheckEquivalence(p1, p2);
	CheckEquivalence(p1, p3);
	CheckEquivalence(p2, p3);
	CheckEquivalence(p1, q1);
}
