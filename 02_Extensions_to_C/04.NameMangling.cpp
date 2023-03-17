////////////////////////////////////////////////////////////
//
//      Name Mangling
//
////////////////////////////////////////////////////////////

/*
 *  Originally, C++ used the same linker as C and as the C linker doesn't allow multiple functions with the 
 *  same name, Stroustrup decided to get the compiler to append symbols to function names based on their 
 *  parameter list to ensure all function names were distinct.  This is called name mangling and is still 
 *  in use today.
 * 
 *  The mangled names are only ued by the linker and you won't see the mangled names in your code.  In fact you
 *  can ignore name mangling unless you try to interface your C++ with some other language such as Python.  You
 *  can stop C++ mangling names if you don't reuse function names and include the prototypes in an extern clause:
 *          extern "C"
 *          {
 *              // function prototypes
 *          }
 * 
 *  One problem with name mangling is that it is compiler dependent.  Here we explore the gcc name mangling
 *  scheme using the "nm" utility.  We can use nm on the command line to see symbols:
 *      nm 4.NameMangling.exe | grep ffffff
 */

#include <cstdlib>
#include <string>
using namespace std;

void ffffff() {}
void ffffff(int x) {}
void ffffff(int x, int y) {}
void ffffff(int x, double y) {}

extern "C"
{
int gggggg(int, int, int);
}

int gggggg(int, int, int) { return 0; }

int main()
{
    // inspect file with hexdump
    string cmd = "nm 04.NameMangling.exe | grep -E 'ffffff|gggggg'"s; 
    system(cmd.c_str());
}

