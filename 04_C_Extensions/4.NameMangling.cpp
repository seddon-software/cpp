////////////////////////////////////////////////////////////
//
//      Name Mangling
//
////////////////////////////////////////////////////////////

/*
 *  Name mangling is where the compiler modifies the function names so the linker
 *  sees diffent names.
 *  Use nm on the command line to see symbols:
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
    string cmd = "nm 4.NameMangling.exe | grep ffffff"s; 
    system(cmd.c_str());
}

