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

class String
{
	friend String operator+(const String&, const String&);
public:
	String(const char* s = "")
	{
		text = new char[strlen(s) + 1];
		strcpy(text, s);
	}

	String(const String& rhs)
	{
		cout << "ref CTOR" << endl;
		cout.flush();
		text = new char[strlen(rhs.text) + 1];
		strcpy(text, rhs.text);
	}

	String(String&& temp)
	{
		cout << "rref CTOR" << endl;
		cout.flush();
		text = temp.text;
		temp.text = 0;
	}

	// use the copy swap idiom for exception safety
	// when we create the temp String we may throw, but won't affect *this
	// if we get as far as Swap we are OK since Swap doesn't throw
	// *this can't be left in an indeterminate state
	// Finally as temp goes out of scope, its DTOR cleans up memory originally assigned to *this
	String& operator=(const String& rhs)
	{
		cout << "ref =" << endl;
		cout.flush();
		if (this == &rhs) return *this;
		String temp(rhs);
		Swap(temp);
		return *this;
	}

	// copy and swap not approriate here, because we want efficiency
	// can't make this exception safe (delete[] may throw)
	String& operator=(String&& rhs)
	{
		cout << "rref =" << endl;
		cout.flush();
		if (this == &rhs) return *this;
		delete[] text;
		text = rhs.text;
		rhs.text = 0;
		return *this;
	}
	void Swap(String& rhs) noexcept
	{
		std::swap(text, rhs.text);
	}
	~String()
	{
		delete[] text;
	}
private:
	char* text;
};

String operator+(const String& lhs, const String& rhs)
{
	String result;
	delete[] result.text;
	result.text = new char[strlen(lhs.text) + strlen(rhs.text) + 1];
	strcpy(result.text, lhs.text);
	strcat(result.text, rhs.text);
	return result;
}

int main()
{
	String s1("ABC");
	String s2("DEFGHI");
	String s3(s1 + s2);		// should call String(String&&)
	String s4;
	s4 = s1 + s2;			// should call String(String&&) and
							// should call operator=(String&&)

}
