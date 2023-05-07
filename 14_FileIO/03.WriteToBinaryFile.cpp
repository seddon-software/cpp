/*
 *  When working with binary file we can use the flag:
 *          ios::binary
 *  but note this has no effect in Linux systems, because there is no difference between text and
 *  binary files (it's provided for Windows platforms).  The flag:
 *          ios::trunc
 *  is used to empty (truncate to zero length) the output file, prior to writing to it.
 */

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#define FILENAME "myfile.dat"


using namespace std;


int main()
{
    vector<char> v;

    // put some binary characters in a vector
    for(int i = 1; i < 128; i++)
    {
        v.push_back(i);
    }
    // push them to a file
    ofstream outStream(FILENAME, ios::binary | ios::trunc);
    outStream.write((const char*)v.data(), v.size()*sizeof(char));
    outStream.close();
    // inspect file with hexdump
    string cmd = "hexdump -cx "s + FILENAME; 
    system(cmd.c_str());
}