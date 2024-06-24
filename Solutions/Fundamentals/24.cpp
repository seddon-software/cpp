/*
 * Write a program that concatenates three files into a new file.
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
	File inFile1("data/InFile1.txt", ios::in);
    File inFile2("data/InFile2.txt", ios::in);
    File inFile3("data/InFile3.txt", ios::in);
    File outFile("data/OutFile.txt",  ios::out);
    istream& in1 = inFile1.getStream();
    istream& in2 = inFile2.getStream();
    istream& in3 = inFile3.getStream();
    ostream& out = outFile.getStream();

    out << in1.rdbuf();
    out	<< in2.rdbuf();
    out << in3.rdbuf();
}

