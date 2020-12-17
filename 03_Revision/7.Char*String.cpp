#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    char* s1="ABC";
    string s2="XYZ";

    cout << s1 << ", " << s2 << endl;
    printf("%s\n", s1);
    printf("%s\n", s2.c_str());    
}

