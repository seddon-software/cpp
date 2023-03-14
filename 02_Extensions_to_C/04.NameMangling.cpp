////////////////////////////////////////////////////////////
//
//      Name Mangling
//
////////////////////////////////////////////////////////////

/*
 *  Originally, C++ used the same linker as C and as the C linker doesn't allow multiple functions with the 
 *  same name, Stroustrup decided to get the compiler to append symbols to function names based on their 
 *  parameter list.  This makes the function names distinct and makes the linker happy.  This is called name
 *  mangling and is still in use today.
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

int main()
{
    // inspect file with hexdump
    string cmd = "nm 04.NameMangling.exe | grep ffffff"s; 
    system(cmd.c_str());
}

