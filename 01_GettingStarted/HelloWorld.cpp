/*
 *  1. #include introduces a set of definitions (not code) into the program
 *  2. The absence of ".h" on the header file indicates the header uses a namespace (std)
 *  3. cout is an object representing the character output buffer
 *  4. endl is the new line object, but includes a flush of the output buffer
 */

#include <iostream>

int main()
{
	std::cout << "Hello World" << std::endl;
}
