///////////////////////////////////////////////////////////////////////////////
//
//  Text Files (read)
//
///////////////////////////////////////////////////////////////////////////////

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
