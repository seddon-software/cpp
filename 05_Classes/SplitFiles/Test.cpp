/*
 *  In this folder you will find the following files:
 *              Point.cpp       : the Point class implementation file
 *              Test.cpp        : the Test harness
 *              Point.h         : header file containing function prototypes for Point class
 * 
 *  This file is the test harness for the Point example.  Note the compiler requires the Point class
 *  to be declared before it is used; hence the inclusion of "Point.h".  When including a file from
 *  the current directory you should use " quotes; if it is a library include file you sould use <>
 *  brackets.
 */ 

#include "Point.h"

int main()
{
    Point p1;
    Point p2;
    Point p3;

    p1.Initialise(700, 100);
    p2.Initialise(100, 300);
    p3.Initialise(600, 600);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();

    p1.MoveBy(10, 10);
    p2.MoveBy(10, 10);
    p3.MoveBy(10, 10);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();
}

