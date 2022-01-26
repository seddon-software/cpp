/*
 *  In this example we create a module called "hello" in the file "hellowWorld.cpp".  Note that the module 
 *  name does not need to be related to the filename that creates it.  Furthermore, large modules can be
 *  defined across several files (see later examples).
 * 
 *  There are two main types of module:
 *      module interface units
 *      module implementation units
 * 
 *  Module interface units are declared with the "export" keyword, whereas module implementation units
 *  are not.
 *  
 *  This file is not a module, but does import the interface module "hello".
 */


import hello; 
 
int main() 
{
    hello();
}
