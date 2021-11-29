///////////////////////////////////////////////////////////////////////////////
//
//  Binary Files (read)
//
///////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#define FILENAME "myfile.dat"

using namespace std;

int main()
{
    // read from binary file we created earlier

    // A stream buffer is an object in charge of performing the reading and writing operations of the 
    // stream object it is associated with: the stream delegates all such operations to its 
    // associated stream buffer object, which is an intermediary between the stream and its 
    // controlled input and output sequences.
    streambuf* pBuffer;
    ifstream inStream(FILENAME);
    if(inStream) 
    {
        // get pointer to associated buffer object
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