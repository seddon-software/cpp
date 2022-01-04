//////////////////////////////////////////////////////////////////////
//
//      Koenig Name Lookup
//
//////////////////////////////////////////////////////////////////////

/*
 *  When an unqualified name is used as a parameter in a function call and it is found by 
 *  unqualified lookup, then its namespace will be searched in lookups for the function name
 *  itself and any other function parameters.
 * 
 *  This is not obvious and has created confusion in the past.  It means clashes with the 
 *  global namespace may occur, even if we have not declared a "using namespace" directive.
 *  since function declarations not otherwise visible may be found.
 */


namespace NS
{
    class T { };
    void f(T){};
}

NS::T parameter;

// if this global function is uncommented, the program will fail to compile
// because the call to f will be ambiguous
/*
void f(NS::T)
{
}
*/

int main()
{
	/* 
     *  f is apparently hidden inside NS, however because parameter is visible from its global
     *  declaration:
     *      NS::T parameter;
     *  the Koenig lookup says that the namespace NS will be included in the search list for f (in
     *  addition to the global namespace).  Fortunately, f() is not defined in the global namespace,
     *  but if it were the call below would be ambiguous (try removing the comments around the
     *  global declaration of f above to verify this).
     */
    f(parameter);
}
