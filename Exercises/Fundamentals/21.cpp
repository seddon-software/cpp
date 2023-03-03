/*
 * Write a file copy program
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
	try
	{
	    File inFile("data/text.txt", ios::in);
	    File outFile("data/copy.txt", ios::out);
	    fstream& in = inFile.getStream();
	    fstream& out = outFile.getStream();

	    string line;
	    while(getline(in, line))
	    {
	    	out << line << endl;;
	    }
	} catch(const FileIOException& e) {
		cerr << e.what() << endl;
	}
}
