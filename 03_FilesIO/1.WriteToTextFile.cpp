///////////////////////////////////////////////////////////////////////////////
//
//  Text Files (write)
//
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>

#define FILENAME "myfile.txt"

using namespace std;
 
int main()
{
    ofstream outFile (FILENAME);
    outFile << "This is line 1.\nThis is line 2.\nThis is line 3.";
    outFile.close();
}
