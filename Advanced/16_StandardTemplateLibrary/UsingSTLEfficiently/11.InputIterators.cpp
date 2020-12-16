#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;


string fileName("resources/myfile.txt");

// using string template
//template<class InputIterator> string (InputIterator begin, InputIterator end);

void attempt1()
{
	// istream_iterator uses operator<<
	ifstream inputFile(fileName);

	string dataFromFile((istream_iterator<char>(inputFile)), // iterator for inputFile
			                                                 // note extra brackets
			                                                 // "most vexing parse"
	                 istream_iterator<char>());	// special EOF iterator

	inputFile.close();
	cout << dataFromFile << endl;
}

void attempt2()
{
	ifstream inputFile(fileName);

	// istreambuf_iterator uses low level routine to read every character
	string dataFromFile((istreambuf_iterator<char>(inputFile)),
					    istreambuf_iterator<char>());
	inputFile.close();
	cout << dataFromFile << endl;
}

int main()
{
	attempt1();
	attempt2();
}
