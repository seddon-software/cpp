/********************************************************************
 *
 *	Querying Records
 *
 *******************************************************************/

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <array>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <iomanip>

using namespace std;


list<string> openTestData(const string& fileName)
{
    // build list containing the test data
	list<string> theList;

	ifstream in(fileName, ios::in);
	if (!in.is_open()) {
	    cerr << "failed to open " << fileName << endl;
	}

	for(string line; getline(in, line); )
	{
	    theList.push_back(line);
	}
    return theList;
}

void print(const vector<pair<string, string>>& fields)
{
	for(auto field:fields)
	{
		cout << setw(16) << field.second << ","; 
	}
	cout << endl;
}

void query(const vector<vector<pair<string, string>>>& records, 
           const vector<string>& header, 
		   const string& column, 
		   const string& value)
{
	cout << "\nQuerying for:" << column << "=" << value << endl << endl;
	for(auto columnName: header)
	{
		cout << setw(17) << columnName;
	}
	cout << endl;

	for(auto record: records)
	{
		for(auto field: record)
		{
			if(field.first == column && field.second == value)
			{
				print(record);
			}
		}
	}
}

std::vector<std::string> split(const string& line)
{
//	cout << line << endl;
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(line);
	char delimiter = ',';
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

int main()
{
	vector<vector<pair<string, string>>> records;

	auto lines = openTestData("sales.csv");
	auto columns = split(lines.front());
	lines.pop_front();
	for (auto& line : lines)
	{
		auto values = split(line);

		vector<pair<string, string>> record;
		vector<string>::iterator ic, iv;
		for(ic = columns.begin(), 
		    iv = values.begin(); 
			ic != columns.end(); ic++, iv++)
		{
			auto p = make_pair(*ic, *iv);
			record.push_back(p);
		}
		records.push_back(record);
	}
	query(records, columns, "Status", "presented");
	query(records, columns, "Product", "CPU");	
}
