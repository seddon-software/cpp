/********************************************************************
 *
 *
 *
 *******************************************************************/

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <iostream>
//#include <filesystem>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;


vector<string> openTestData(const string& fileName)
{
    // build list containing the test data
	vector<string> v;

	ifstream in(fileName, ios::in);
	if (!in.is_open()) {
	    cerr << "failed to open " << fileName << endl;
	}

	for(string line; getline(in, line); )
	{
	    v.push_back(line);
	}

    return v;
}
struct Record
{
	string account;
	string name;
	string rep;
	string manager;
	string product;
	string quantity;
	string price;
	string status;

};

int main()
{
//	namespace fs = std::filesystem;
//    std::cout << "Current path is " << fs::current_path() << '\n';
	auto lines = openTestData("sales.csv");
	for (auto& line : lines)
	{
		cout << line << endl;
		std::vector<std::string> tokens;
		std::string token;
		std::istringstream tokenStream(line);
		char delimiter = ',';
		while (std::getline(tokenStream, token, delimiter))
		{
			tokens.push_back(token);
		}
		Record a;
		a.account = tokens[0];
		a.name = tokens[1];
		a.rep = tokens[2];
		a.manager = tokens[3];
		a.product = tokens[4];
		a.quantity = tokens[5];
		a.price = tokens[6];
		a.status = tokens[7];
	}
}
