// override - 	If a virtual function is marked with override and does not
//				override a member function of a base class (including matching
//				the function signature), the program is ill-formed.



struct B
{
    virtual void f(int);
};

struct D : B {
    // virtual void f(long) override;  // error: wrong signature overriding B::f
    virtual void f(int) override; 	 // OK
};


int main()
{
}
