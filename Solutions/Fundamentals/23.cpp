/*
 * Try the previous example with other test files that may contain
 * non integral data.  Use exception handling to filter out lines
 * that don't contain integers.
 */


#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;


class FileIOException: public exception
{
public:
	FileIOException(const string& message): message(message) {}
	virtual const char* what() const noexcept
	{
		return message.c_str();
	}
private:
	string message;
};

class File
{
public:
	File(const string& fileName, ios_base::openmode mode)
	{
		f.open(fileName, mode);
		if(!f.is_open())
		{
			throw FileIOException("can't open file:" + fileName);
		}
	}
	~File()
	{
		f.close();
	}
	fstream& getStream()
	{
		return f;
	}
private:
	fstream f;
};


int main()
{
	int total = 0;
	int x;

	File inFile("data/TestData2.txt", ios::in);
	fstream& in = inFile.getStream();
	while(!in.eof())
	{
		in >> x;
		if(in.good())
		{
			total += x;
		}
		else
		{
			in.ignore();
		}
	}
	cout << "Total = " << total << endl;
}
