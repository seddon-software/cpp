/*
 *  Modules are translation units (like object files) and can be passed to the C++ linker to build
 *  executables.  Usually we make the module exportable so that it can be referred to from outside the
 *  module.
 * 
 *  Functions defined in the module can be public (if exported) or private otherwise.
 * 
 *  Modules frequently will need to import other modules, particularly standard library modules, as in:
 *      import <iostream>;
 *  
 *  Note that in all cases, imported modules must be already built - see Makefile for details on how 
 *  to do this for g++ (other compilers vary). 
 * 
 *  Please debug this example from main.cpp (not this file).
 */ 

export module hello;        // export => this module unit can be imported in another file

import <iostream>;          // must be already built - see Makefile
using namespace std;

void world()                // no export declaration (not visible in other translation units) 
{
    cout << "World!" << endl;
}

export void hello()         // export declaration (visible in other translation units) 
{
    cout << "Hello ";
    world();
}

