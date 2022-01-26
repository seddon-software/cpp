/* 
 *  Let's begin by stating there is no such thing as a sub-module.
 *
 *  In this example we have 3 interface modules: "speech", "speech.english" and "speech.spanish".  
 *  Note that having a dot in the module name does NOT create a sub-module.  The dot is not a 
 *  significant character as far as the compiler is concerned, but merely used as a convienience 
 *  to the programmer.  So although
 *          speech.english and 
 *          speech.spanish
 *  look like sub-modules, in reality they are regular interface module, but with a dot in their names.
 * 
 *  Here, the main program imports the "speech" module, which in turn imports the other 2 modules, 
 *  making code in these modules available to main.
 */

import speech;

import <iostream>;
import <stdlib.h>;
import <cstdlib>;

using namespace std;

int main() {
    srand(time(0));
    if (rand() % 2) {
        cout << get_phrase_en() << '\n';
    } else {
        cout << get_phrase_es() << '\n';
    }
}
