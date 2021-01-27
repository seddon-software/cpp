////////////////////////////////////////////////////////////
//
//      manipulating in memory strings
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include <cstdio>
#include <cstring>

using namespace std;

// split a string into individual words

void c_version() 
{
    char str[] = "The quick brown fox jumped over the lazy dog";
    char *token;
   
    /* get the first token */
    token = strtok(str, " ");
   
    /* get remaining tokens */
    while(token != 0) {
        printf("%s\n", token );
        token = strtok(0, " ");
    }
}

void cpp_version() 
{
    string str("The quick brown fox jumped over the lazy dog");
    string word;
    stringstream s(str);
    vector<string> words;
    
    while (s >> word) 
    {
        words.push_back(word);
    }
    for(unsigned i = 0; i < words.size(); i++)
    {
        cout << words[i] << endl;
    }
}

int main()
{
    c_version();
    cout << "=======================" << endl;
    cpp_version();
}
