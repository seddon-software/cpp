////////////////////////////////////////////////////////////
//
//      Using string in place of char*
//
////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <cstdio>   // for printf 
#include <cstring>  // for strcat, strcmp

using namespace std;

char c1[]="ABC";
char c2[]="XYZ";
string s1="ABC";
string s2="XYZ";

void compare()
{
    if(!strcmp(c1, c2))   // note !
        printf("same\n");
    else
        printf("different\n");

    if(!strcmp(s1.c_str(), c1))  // c_str() extracts internal char*
        printf("same\n");
    else
        printf("different\n");

    if(s1 == s2)
        cout << "same" << endl;
    else
        cout << "different" << endl;
    
    if(s1 == string(c1))        // use string CTOR to convert char* to string
        cout << "same" << endl;
    else
        cout << "different" << endl ;
}

void combine()
{
    printf("%s\n", strcat(c1, c2));
    cout << s1 + s2 << endl;
}

int main()
{
    compare();
    combine();
}

