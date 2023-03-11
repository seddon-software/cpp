/*
 *  1. #include introduces a set of definitions (not code) into the program
 *  2. The absence of ".h" on the header file indicates the header uses a namespace (std)
 *  3. cout is an object representing the character output buffer
 *  4. endl is the new line object, but includes a flush of the output buffer
 
 DECLARATIONS: A declaration introduces a name into a scope. Generally speaking, a scope is 
 either an entire .cpp file or anything in code delimited by {}, be it a function, a loop 
 within a function, or even an arbitrarily placed block of {} within a function. A name 
 introduced, is visible within the scope from the point at which it is declared to the end 
 of that scope. A declarations merely tells the compiler how to use something, it does not 
 actually create anything.
 
 DEFINITIONS: A definition fully specifies an entity. Definitions are where the actual creation 
 of the entity in memory takes place. All definitions are also declarations, but not all 
 declarations are definitions.
 */

#include <iostream>

int main()
{
	std::cout << "Hello World" << std::endl;  // note some people prefer "\n" to endl as its usually 
                                              // more efficient
}
