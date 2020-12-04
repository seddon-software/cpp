//////////////////////////////////////////////////////////////////////
//
//      Koenig Name Lookup
//
//////////////////////////////////////////////////////////////////////

// When an unqualified name is used as the postfix-expression in a 
// function call, other namespaces not considered during the usual 
// unqualified lookup may be searched, and namespace-scope friend 
// function declarations not otherwise visible may be found. These 
// modifications to the search depend on the types of the arguments...


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
	// f is apparently hidden inside NS, however because parameter is visible
	// Koenig lookup says that NS is searched for f
    f(parameter);
}
