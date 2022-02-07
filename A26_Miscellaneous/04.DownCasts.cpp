///////////////////////////////////////////////////////////////
//
//		Down Casts
//
///////////////////////////////////////////////////////////////

/*
 *  With inheritance hierarchies it is common to perform up-casts.  These are where a derived object (or 
 *  pointer) is converted to an object higher uphierarchies, for example to a base class object.  With
 *  public inheritance this works because of the substitution rule (or ISA rule); a derived object can
 *  substitute for an object higher up the hierarchy.
 * 
 *  A down-cast goes the other way and is not allowed.  However, we can define a base class pointers 
 *  and assign it to a derived class object, as in:
 *              A* pb = new B
 *              A* pc = new C 
 *  In these cases the compile can have problems determining if further casts are legal.  For example
 *              B* qb = (B*) pb
 *  Here this is OK because despite being pb being declared as a A*, it is actually a pointer to a B
 *  object.  On the other hand:
 *	            B* qc = (B*)pc
 *  tries to convert pc to a B*.  However in this case this should be illegal, because pc is a pointer
 *  to a C object and we are making a down-cast.  Old style casts, such as the above will always succeed, 
 *  even in the last situation.  If we use dynamic_casts, the compiler will generate code to make the 
 *  check for a valid cast using v-tables; the dynamic_cast will return a null pointer if the cast is 
 *  illegal (down-cast).
 * 
 *  Note that for the dynamic_cast to succeed we need v-tables, which implies there must be a least one 
 *  virtual function in the base class.
 */

class A 
{
public:
    virtual void f() {}
};

class B : public A 
{
public:
    virtual void f() {}
};

class C : public B 
{
public:
    virtual void f() {}
};

int main()
{
	A* pa = new A;                  // legal: *pa <IS A KIND OF> A
    A* pb = new B;                  // legal: *pb <IS A KIND OF> A
    A* pc = new C;                  // legal: *pc <IS A KIND OF> A

	B* qa = dynamic_cast<B*>(pa);	// error: pa does not point  to a <KIND OF> B
	B* qb = dynamic_cast<B*>(pb);	// ok:    pb          points to a <KIND OF> B
	B* qc = dynamic_cast<B*>(pc);	// ok:    pc          points to a <KIND OF> B

    if (qa != 0) qa->f();
    if (qb != 0) qb->f();
    if (qc != 0) qc->f();
}
