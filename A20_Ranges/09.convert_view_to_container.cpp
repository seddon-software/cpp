#include <iostream>
#include <cxxabi.h>    // gcc specific header to demangle names
#include <ranges>
#include <vector>

/*  
 *  The C++20 ranges library doesn't provide a generic method to convert a view back to a range (although this 
 *  is provided in Eric Niebler's excellent range-v3 library:
 *              https://github.com/ericniebler/range-v3)
 * 
 *  However, if the begin iterator and end sentinel are of the same type we can convert a view to a container 
 *  with the current library.
 */

using namespace std;


const char* demangle(auto p)
{
	int status;  // did the demangle work?
	const char* realname = abi::__cxa_demangle(typeid(p).name(),0,0,&status);  // gcc specific code (see Makefile)
	return realname;
}

int main()
{   
    // create a view
    auto numbers = std::ranges::views::iota(20, 30);
    cout << "type of numbers: " << demangle(numbers) << endl;
    
    // create begin iterator and sentinel
    auto begin = std::ranges::begin(numbers); 
    auto sentinel = std::ranges::end(numbers); 

    // check iterator and sentinel are of the same type
    cout << "type of begin iterator: " << demangle(begin) << endl;
    cout << "type of end sentinel:   " << demangle(sentinel) << endl;

    // create a range from the iterators
    auto v = std::vector(begin, sentinel);
    cout << "type of v: " << demangle(v) << endl;

    // print the vector (i.e. the range)
    for(auto i : v) cout << i << "," << flush;
    cout << endl;
}
