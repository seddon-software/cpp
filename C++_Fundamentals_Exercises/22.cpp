/*
 * Create a file call TestData.txt with test data consisting of one
 * number per line using your favourite editor.  Your job is to read
 * the entire file into memory so that you can compute the sum of all
 * the numbers.
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

	File inFile("data/TestData.txt", ios::in);
	fstream& in = inFile.getStream();
	while(!in.eof())
	{
		in >> x;
		if(!in.fail())
			total += x;
	}
	cout << "Total = " << total << endl;
}
