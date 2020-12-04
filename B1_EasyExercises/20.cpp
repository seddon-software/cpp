/*
 * Write a program that counts the number of lines in a file.
 * Create a File class to represent the file and user defined exception
 * class to use if you can't open the file.
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
	File(const string& fileName)
	{
		f.open(fileName, ios::in);
		if(!f.is_open())
		{
			throw FileIOException("can't open file:" + fileName);
		}
	}
	~File()
	{
		f.close();
	}
	ifstream& getStream()
	{
		return f;
	}
private:
	ifstream f;
};

int countLines(const string& filename)
{
	File f(filename);
	string line;
	int count = 0;

	while(getline(f.getStream(), line))
	{
		count++;
	}

//	theFile.close();
	return count;
}


int main()
{
    try
	{
		cout << "count = " << countLines("data/text.txt") << endl;
		cout << "count = " << countLines("unknown.txt") << endl;
	} catch(const FileIOException& e) {
		cerr << e.what() << endl;
	}
}
