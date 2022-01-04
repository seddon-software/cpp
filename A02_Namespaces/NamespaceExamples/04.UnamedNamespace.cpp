#include <iostream>
using namespace std;

int k = 100;  

/* 
 *  If you don't give a namespace a name, it acts as if you are declaring global symbols.
 *  Thus symbols such as:
 *      ::k
 *  belong to the unnamed namespace (i.e. are global).
 */

namespace 
{
    // all symbols behave as global
    int j = 300;  // refer to j as ::j
}

int main()
{
    // k is both local and global, use :: to differentiate between them
    int k = 200;
    cout << k << endl;    // k is the local k
    cout << ::k << endl;  // ::k is the global k
    cout << ::j << endl;  // ::j is from the unnamed namespace (i.e. global)
    cout << j << endl;    // no need for :: as there is no local variable called j
}
