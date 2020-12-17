/*
 * Write a program that reads a file, reverses the order of lines in
 * the file and then saves the changes in a new file.
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>

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
	File original("data/text.txt", ios::in);
	File reversed("data/reversed.txt", ios::out);
	vector<string> lines;

	istream& is = original.getStream();
	ostream& os = reversed.getStream();
	string line;

	while(getline(is, line))
	{
		lines.push_back(line);
	}
	for(auto it = lines.rbegin(); it != lines.rend(); ++it)
	{
		os << *it << endl;
	}
}

/*(
inFile = None
outFile = None

try:
    inFile = open("../data/original.txt", "r")
    outFile = open("../data/reversed.txt", "w")

    listOfLines = list()
    for line in inFile:
        listOfLines.insert(0, line)
    
    for line in listOfLines:
        outFile.write(line)
        
except IOError, reason:
    print reason
finally:        
    if inFile: inFile.close()
    if outFile: outFile.close()


1
*/
