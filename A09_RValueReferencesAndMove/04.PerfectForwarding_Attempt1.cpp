////////////////////////////////////////////////////////////
//
//		Perfect Forwarding
//
////////////////////////////////////////////////////////////

/*
 *  The problem we are trying to solve with perfect forwarding is: How can we write a function template
 *  that forwards calls to another function template without changing l-vaues into r-values.
 *
 *  It turns out this is very difficult without using the new r-value references.  We'll make several 
 *  attempts without r-value references to see why this is difficult and then show the r-value 
 *  reference solution.
 */


template<class A1, class A2, class A3>
void f(A1& a1, A2& a2, A3& a3)
{
	// put a breakpoint here and get the IDE to check types
}

// this is a wrapper template that forwards all parameters
// to another template
template<class A1, class A2, class A3>
void fwd(A1 & a1, A2 & a2, A3 & a3)
{
    return f(a1, a2, a3);
}

int main()
{
	int x{1}, y{2}, z{3};
    fwd(x, y, z);       // parameters passed as l-values OK

// The template doesn't work with r-values
//    fwd(1, 2, 3);

}
