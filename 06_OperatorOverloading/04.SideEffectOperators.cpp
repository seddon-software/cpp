/*
 *  You can also overload the ++ and -- operators in your class.  Typically you write code that will behave 
 *  in a similar fashing to how these operators behave in C.
 * 
 *  Just to recap, the code:
 *          int x = 100
 *          int y;
 *          y = x++ 
 * 
 *  means y is set to x before x is incremented, but in the code:
 *          int x = 100
 *          int y;
 *          y = ++x 
 * 
 *  the increment to x is performed before the assignment.
 * 
 *  The plan is to emulate this in our own classes (e.g. the Time class). Thus
 *          t = t1++;       // assigns to t first and then increments t1 and
 *          t = ++t2;       // increments t2 and the assigns to t.
 * 
 *  Recall that when we use operators in our own class the compiler will translate the code to use operator
 *  functions:
 *          t = ++t2        // translates to: t = t2.operator++() 
 *  whereas
 *          t = t1++;       // translates to: t = t.operator++(0)
 * 
 *  and note the 0 in the last translation.  This is a kludge by the author of C++ (Bjarne Stroustrup) to
 *  define different operator functions for these two cases.  Further note that ++ is a unary operator; hence
 *  no explicit parameter (this is implicit)
 * 
 *  When we write code for these functions we essentially need to write:
 *          operator++()        // prefix
 *          {
 *              increment *this
 *              return *this
 *          }
 * 
 *          operator++(int)     // postfix
 *          {
 *              return *this
 *              increment *this
 *          }
 * 
 *  Note that in the postfix code the return is not the last thing in the function, so we can't directly 
 *  code the above; we need to modify it to:
 *          operator++(int)     // postfix
 *          {
 *              snapshot = *this
 *              increment *this
 *              return snapshot
 *          }
 */

class Time
{
public:
	Time& operator++();     // prefix
	Time operator++(int);   // postfix with spurious int parameter (always 0)

    // default CTOR
    Time(): hrs(0), min(0) {}
    Time(int h, int m): hrs(h), min(m) {}
    // copy CTOR
    Time(const Time& original): hrs(original.hrs), min(original.min) {}
    // DTOR
    ~Time() {}
private:
    int hrs;
    int min;
};

// prefix
Time& Time::operator++()
{
    // increment *this
	min++;
	if(min == 60)
	{
		min = 0;
		hrs++;
	}
    return *this;
}

// postfix
Time Time::operator++(int)
{
	// take snapshot
	Time snapshot(*this);
	++(*this);      // call the postfix
    return snapshot;
}

int main()
{
    Time t;
    Time t1(4, 30);
    Time t2(3, 15);

    t = t1++;		// t = t1.operator++(0);
    t = ++t2;		// t = t2.operator++();
}

