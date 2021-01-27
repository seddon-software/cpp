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
    streambuf* pBuffer;
    ifstream inStream(FILENAME);
    if(inStream) 
    {
        pBuffer = inStream.rdbuf();

        do {
            char ch = pBuffer->sgetc();
            cout << ch;
            cout.flush();
        } while (pBuffer->snextc() != EOF);
        cout << endl;
        inStream.close();
    }
    else
    {
        cerr << "can't open: " << FILENAME << endl;
    }
}