#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/*
 *  You can use recursion with fold expressions.  Here we deine a generic template for our function
 *  "commaSeparatedList".  This function template only takes a sing parameter.  Contrast that with 
 *  the specialized template that has a single parameter followed by a parameter pack.  The 
 *  specialized template will be used whenever "commaSeparatedList" is called with more than 1
 *  parameter.  This specialized template is recursive and will call itself while the parameter 
 *  pack is not empty (it checks this with the new sizeof... operator).
 */

// generic template
template<typename T>
T commaSeparatedList(T t)
{
    return t;
}

// specialization with parameter pack
template<typename T, typename... P>
T commaSeparatedList(T t, P... p)
{
    cout << t << ",";
    if (sizeof...(p) > 0)	// if size of parameter pack non zero
        return commaSeparatedList (p...);
        
    return 99;  // not used
}


int main() 
{
    cout << commaSeparatedList(1, 2, 3, 4) << endl;	
}
