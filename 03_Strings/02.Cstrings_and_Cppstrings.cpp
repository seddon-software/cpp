#include <string>
#include <iostream>
#include <cstdio>   // for printf 
#include <cstring>  // for strcat, strcmp

using namespace std;

/*
 *  One of the biggest changes in C++ from C is the introduction of the string type.  In C we have to use 
 *  character arrays, or char*s.  In new projects it's best to avoid char*s, but many C++ projects were
 *  written during the 1980s and 1990s and make extensive use of char*s.  
 * 
 *  For these legacy projects it is important to be able to convert between char*s and C++ strings.
 *  Here we consider comparing char* and strings and also how to join or concatenate char*s and strings.
 *  
 *  The C++ strings store a char* internally and have a method c_str() to extract this char*. 
 */

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

