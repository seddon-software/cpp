////////////////////////////////////////////////////////////
//
//		String with move symantics
//
////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*  The idea behing the move CTOR is to avoid an expensive copying operation when one of the objects
 *  is about to go out of scope (i.e. a temporary).  The remaining object effectively steals the
 *  temporary's resourses (usually from the heap), taking care not to let the temporary delete 
 *  the resource it is stealing (ususually the temporary's pointer to the heap is set to a null 
 *  pointer, so that its DTOR does nothing).
 * 
 *  In this example we write our own String class to illustrate the use of the move CTOR and 
 *  how you can use r-value refs in operator=().  Note that C++17 introduced mandatory copy
 *  elision with most copy operations, so move constructors are not now called when constructing
 *  from temporaries.  To force the use of a move CTOR you have to use std::move as CTOR parameter.
 * 
 *  Furthermore, note the use of the copy and swap idiom in the l-value reference version of the
 *  operator=() overload to make it exception safe.  We've also included and r-value reference 
 *  version for working with temporaries (which s efficient, but not exception safe).  If the
 *  r-value reference overload is omitted the the l-value reference overload will be used instead.
 */

class String
{
public:
	String(const char* s = "")
	{
		text = new char[strlen(s) + 1];
		strcpy(text, s);
	}

	String(const String& rhs)
	{
		cout << "copy CTOR called" << endl;
		cout.flush();
		text = new char[strlen(rhs.text) + 1];
		strcpy(text, rhs.text);
	}

	String(String&& temp)
	{
		cout << "move CTOR called" << endl;
		cout.flush();
		text = temp.text;
		temp.text = 0;
	}

	// use the copy swap idiom for exception safety
	// when we create the temp String we may throw, but won't affect *this
	// if we get as far as Swap we are OK since Swap doesn't throw
	// *this can't be left in an indeterminate state
	// finally as temp goes out of scope, its DTOR cleans up memory originally assigned to *this
	String& operator=(const String& rhs)
	{
		cout << "operator=(String&) called" << endl;
		if (this == &rhs) return *this;  // check for self copy
		cout << "preparing for swap idiom" << endl;
		String temp(rhs);  // this may throw
        // if we get this far, all is well and we won't throw now
		Swap(temp);     // swap with *this
		return *this;
	}

	// copy and swap not approriate here, because we want efficiency
	// however, can't make this exception safe (delete[] may throw)
	// if this method is removed, assignment will default to operator=(String&)
	String& operator=(String&& rhs)
	{
		cout << "operator=(String&&) called" << endl;
		cout.flush();
		if (this == &rhs) return *this;
		delete[] text;
		text = rhs.text;
		rhs.text = 0;
		return *this;
	}
	String operator+(const String& rhs) const
	{
        cout << "operator+ called" << endl;
		String result;
		delete[] result.text;
		result.text = new char[strlen(text) + strlen(rhs.text) + 1];
		strcpy(result.text, text);
		strcat(result.text, rhs.text);
		return result;
	}
	void Swap(String& rhs) noexcept
	{
		std::swap(text, rhs.text);
	}
	~String()
	{
		delete[] text;
	}
    friend ostream& operator<<(ostream& os, const String& rhs);
private:
	char* text;
};

ostream& operator<<(ostream& os, const String& rhs)
{
    return os << rhs.text;
}


int main()
{
	String s1{"ABC"};
	String s2{"DEFGHI"};
	String s3{s1};			// calls copy CTOR
	s1 = s2 + s3;			// calls operator=(String&&)
	s3 = s2;			    // calls operator=(String&) 
    String s4{s1+s2};		// copy elision (move CTOR not called)
    cout << "s4=" << s4 << endl;
    String s5{std::move(s4)};	// force move CTOR to be called (s4 will now be invalid)
    cout << "s5=" << s5 << endl;
}
