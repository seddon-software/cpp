///////////////////////////////////////////////////////////////////////////////
//
//  Binary Files (write)
//
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#define FILENAME "myfile.dat"

using namespace std;

int main()
{
    vector<char> v;

    for(int i = 33; i < 128; i++)
    {
        v.push_back(i);
    }
    ofstream outStream(FILENAME, ios::binary | ios::trunc);
    outStream.write((const char*)v.data(), v.size()*sizeof(char));
    outStream.close();
}