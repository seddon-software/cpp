/*
 *  1. #include introduces a set of definitions (not code) into the program
 *  2. The absence of ".h" on the header file indicates the header is namespace aware (std)
 *  3. cout is an object representing the character output buffer
 *  4. endl is the new line object, but includes a flush of the output buffer
 *
 *  If you don't like writing:
 *              std::
 * 
 *  in front of all your library calls you are not alone.  If you use:
 *              using namespace std;
 * 
 *  then you don't have prepend std:: everywhere.  However, many developers don't like the using 
 *  namespace directive and claim its use is bad practice; there are lots of opinions
 *  on the web.  Suffice to say that the concensus is: 
 * 
 *      The use of the directive in source files is good practice, but not in header files.  This 
 *      is because by using the directive in header files, it permeates through to all source files 
 *      that include the header, thereby imposing the directive on developers who do not wish to use it.
 * 
 *  The use of std::endl also generates a lot of discussion.  In truth:
 *	            std::cout << "Hello World" << std::endl;
 *  
 *  is equivalent to
 *	            std::cout << "Hello World" << "\n" << std::flush;
 *
 *  thereby making extra calls to the << operator and forcing a flush of the output buffer.  This in
 *  turn introduces a small amount of inefficiency.  Usually,
 *              std::cout << "Hello World\n";
 * 
 *  achieves the same thing since "\n" normally flushes the output buffer.  However, this can become an 
 *  issue if you write a lot of output statements and particlarly if stdout is redirected to a network file.
 *  In this case repeated flushng of the output buffer is undesirable.

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
