/*
 *  r-value references were introduced into C++11 to solve 2 problems:
 *              avoid the unneccessary deep copying of temporary objects
 *              perfect forwarding
 * 
 *  For the first problem:
 * 
 *  Variable length objects such as string and vector use the heap to store the variable part of these 
 *  objects.  When such objects are returned by value from a function, we want to avoid duplicating the 
 *  heap based part of the object since the returned object will immediately cleaned up as the function 
 *  completes and the object goes out of scope.  C++11 introduces "move" semantics to get round this 
 *  problem.
 * 
 *  Effectively, the "copy" will steal the heap part of the object going out of scope.  This will be OK
 *  because the original object will not be used again.
 * 
 *  For the second problem:
 *
 *  When a function template calls another function template we want each parameter to retain their c-v 
 *  qualification.  In other words const parameters are forwarded as const and non-const parameters
 *  are forwarded as non-const.  This is called perfect forwarding.  It turns out that this was very 
 *  difficult to achieve prior to C++11.
 * 
 *  In this chapter we investigate both move semantics and perfect forwarding.  C++11 introduces r-value
 *  references to solve both problems; new syntax is used:
 *              T&& t;          // t is an r-value reference
 */

int main()
{

}