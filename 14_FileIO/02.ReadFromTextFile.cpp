/*
 *  Similarly, to input from a disk file we use ifstream.  If we are working with a text file, it is often 
 *  easiest to use getline to read in a line of text.  Note that you should check in case you've not
 *  specified the filename correctly as in:
 *              if(inStream)
 */

#include <fstream>
#include <string>
#include <iostream>

#define FILENAME "myfile.txt"

using namespace std;
 
int main()
{
    string line;
    ifstream inStream(FILENAME);
    if(inStream)
    { 
        while(!inStream.eof())
        {
            getline(inStream, line);
            cout << line << endl;
        }
        inStream.close();
    }
    else{
        cerr << "can't open file: " << FILENAME << endl;
    }
}
