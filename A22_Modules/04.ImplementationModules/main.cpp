/* 
 *  As an alternative to interface modules we can use implementation modules.  Entities declared within 
 *  an implementation unit are visible only to the module of which they belong.  We can use implementation
 *  modules to hide module implementation details.  This topic is explored in this example.
 *  
 *  If you examine the "speech" implementation module, you will notice 2 function prototypes are exported,
 *  making these function visible to main:
 *          export const char* get_phrase_en();
 *          export const char* get_phrase_es();
 * 
 *  However, the implementations of these functions are hidden from main as they are defined as private 
 *  in "speech_impl.cpp".
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
