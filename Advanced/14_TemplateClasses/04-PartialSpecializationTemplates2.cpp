class X {
  public: X() {}
};
class Y {};
class Z {};

/////

template<typename T, typename U>	// generic template
struct A
{
	void f(T t,U u) {}
};

// partial specialisations
template<typename T, typename U>
struct A<T*, U>
{
	void f(T* t, U u) {}
};

template<typename T, typename U>
struct A<T, const U>
{
	void f(T t, const U u) {}
};

template<typename T, typename U>
struct A<T, U*>
{
	void f(T t, U* u) {}
};

template<typename T>
struct A<T,T>
{
	void f(T t, T u) {}
};

template<>		// full specialization
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

	// create objects and call specialized templates
	A<X,Y>  a1;       a1.f(x, y);
	A<X*,Y> a2;       a2.f(px, y);
	A<X, const Y> a3; a3.f(xc, y);
	A<X, Y*> a4;      a4.f(x, py);
	A<X, X> a5;       a5.f(x, x);
	A<Z, Y> a6;       a6.f(z, y);
}

