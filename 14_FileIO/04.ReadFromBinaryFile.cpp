/*
 *  In this example we read from a binary file (we created earlier) using the ifstream class.  However,
 *  it is convenient to use the stream buffer object associated with the stream to perform the reading and 
 *  writing operations.
 */


#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#define FILENAME "myfile.dat"

using namespace std;

int main()
{
    streambuf* pBuffer;
    ifstream inStream(FILENAME);
    if(inStream) 
    {
        // get pointer to the associated buffer object
        pBuffer = inStream.rdbuf();

        do {
            char ch = pBuffer->sgetc();  // get character at current position
            cout << ch;
            cout.flush();
        } while (pBuffer->snextc() != EOF);  // advance to next character and check for EOF
        cout << endl;
        inStream.close();
    }
    else
    {
        cerr << "can't open: " << FILENAME << endl;
    }
}