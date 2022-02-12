///////////////////////////////////////////////////////////////////////////////
//
//  Text Files (write)
//
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <fstream>
#include <iostream>

#define FILENAME "myfile.txt"

/*
 *  The ofstream class is used to output to a file.  In this example we write a few lines to a 
 *  disk file.  It is important to close the file - this releases buffers held in memory by the 
 *  C++ runtime.
 */

using namespace std;
 
int main()
{
    ofstream outFile(FILENAME);
    outFile << "This is line 1.\nThis is line 2.\nThis is line 3.";
    outFile.close();

    string cmd = "cat "s + FILENAME; 
    system(cmd.c_str());
    cout << endl;
}
