////////////////////////////////////////////////////////////
//
//		Const Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*
 *  Demonstration const cast: the print function takes a non const char
 *  so we need to remove the constness of c before we can print it
 */

void print(char* str)
{
	cout << str << endl;
}

int main()
{
	char s[] = "text";
	const char c[] = "text";

	print(s);
	print(const_cast<char *>(c));

}
