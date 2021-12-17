////////////////////////////////////////////////////////////
//
//		Perfect Forwarding
//
////////////////////////////////////////////////////////////


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
    fwd(x, y, z);

// The template doesn't work with r-values
//    fwd(1, 2, 3);

}
