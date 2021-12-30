#include <memory>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
using namespace std;

/*  The std namespace provides two smart pointers: unique_ptr and shared_ptr.  The unique_ptr (illustrated
 *  here) manages a unique (body) object and controls its lifetime.  When the unique_ptr goes out of scope
 *  its DTOR deletes the body.  This is usually used to ensure heap based objects are properly cleaned up,
 *  even in the presence of exceptions.
 * 
 *  The unique_ptr in this example is stack based and this would seem to suggest that the lifetime
 *  of the body is restricted to the scope of the unique_ptr.  Although this is true, we can extend the 
 *  scope of the unique_ptr by using a vector and passing a reference to the vector to other functions (see 
 *  a later example); this allows the smart pointer to be passed around between many functions.  
 *  Alternatively, you can use a shared_ptr to achieve this is a simpler way.
 */

int main()
{
	// set up a stack frame
	{
		// unique_ptr is an example of Handle Body, and the Body must be on the heap
		unique_ptr<int> q1;
		// *q1 = 23; // => generates runtime error (23 is not on the heap)

		unique_ptr<int> q2(new int(5));		// OK, 5 is on the heap

		// unique_ptr has private COPY CTOR to prevent copying
		// unique_ptr<int> p2 = p1; // => generates compile error

		// to transfer ownership use explicit move
		q1 = std::move(q2);
		cout << *q1 << endl;
		q1.reset(); // deletes the body before leaving the stack frame
	}
}

