#include <iostream>
#include <iomanip>
#include <fstream>
#include <iterator>
using namespace std;

/*
 *  Here we investigate reading a text file from disk using the following iterators:
 *      istreambuf_iterator: iterator for unformatted extraction.
 *      istream_iterator:   iterator for formatted extraction (removes white space by default)
 * 
 *  This example includes the "most vexing parse".  This is where brackets differentiate between
 *  function and variable declarations as in the following:
 *
 *      A a( A() );         // this is a function declaration
 *      A a( (A()) );       // this is a variable definition
 * 
 *  You can find a number of articles onn the web re: the most vexing parse.  Maybe you'll find 
 *  them interesting.
 */ 

string fileName("resources/myfile.txt");

struct Args
{
    bool ignoreWhiteSpace;
};

void read_file_using_istream_iterator(Args args)
{
    // using string CTOR template
    // template<class InputIterator> string (InputIterator begin, InputIterator end);
    ifstream inputFile(fileName);
    if(!args.ignoreWhiteSpace) noskipws(inputFile);
    string dataFromFile((istream_iterator<char>(inputFile)), // iterator for inputFile
                                                             // note extra brackets
                                                             // "most vexing parse"
                         istream_iterator<char>());          // special EOF iterator

    inputFile.close();
    cout << dataFromFile << endl << endl;
}

void read_file_using_istreambuf_iterator()
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
    read_file_using_istream_iterator({.ignoreWhiteSpace = false});  // using  designated initializers
    read_file_using_istream_iterator({.ignoreWhiteSpace = true});
    read_file_using_istreambuf_iterator();
}
