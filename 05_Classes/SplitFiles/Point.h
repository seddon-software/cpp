/*
 *  This is the header file for the Point class.  It contains declarations for all the methods of the
 *  Point class and is included by the two source files in this folder.  Since each source file is
 *  compiled separately, the compiler needs the information contained herein so that it can check
 *  method names and parameters are used correctly.
 */

#include <iostream>
using namespace std;

class Point
{
public:
    void Initialise(int, int);
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

