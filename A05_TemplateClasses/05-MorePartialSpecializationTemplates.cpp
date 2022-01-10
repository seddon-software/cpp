
/* 
 *  Here are some more examples of template specializations.  Note that struct and class are
 *  interchangeable for public only classes.
 * 
 *  It is intended you step through this code in the debugger - no output statements are included in 
 *  the code.
 */

// some example classes to use ...
class X {
  public: X() {}
};
class Y {};
class Z {};

/////
// the generic template
template<typename T, typename U>	
struct A
{
	void f(T t,U u) {}
};

// partial specialisation: T is a pointer
template<typename T, typename U>
struct A<T*, U>
{
	void f(T* t, U u) {}
};

// partial specialisation: U is const
template<typename T, typename U>
struct A<T, const U>
{
	void f(T t, const U u) {}
};

// partial specialisation: U is a pointer
template<typename T, typename U>
struct A<T, U*>
{
	void f(T t, U* u) {}
};

// partial specialisation: T and U are the same type
template<typename T>
struct A<T,T>
{
	void f(T t, T u) {}
};

// full specialization for T==Z and U==Y
template<>		
struct A<Z,Y>
{
	void f(Z t, Y u) {}
};

int main()
{
	// create artifacts
	X x;
	Y y;
	Z z;
	const X xc;
	X* px = &x;
	Y* py = &y;

	// create objects and call methods on templates
	A<X,Y>  a1;       a1.f(x, y);		// calls generic template
	A<X*,Y> a2;       a2.f(px, y);		// calls specialization: T is a pointer
	A<X, const Y> a3; a3.f(xc, y);		// calls specialization: U is const
	A<X, Y*> a4;      a4.f(x, py);		// calls specialization: U is a pointer
	A<X, X> a5;       a5.f(x, x);		// calls specialization: T and U are same type
	A<Z, Y> a6;       a6.f(z, y);		// calls full specialization: T==Z and U==Y
}

