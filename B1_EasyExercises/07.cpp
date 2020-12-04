/*
 * Split a fullname such as "Julius Caesar"
 * into two strings called firstName and lastName.
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{

	string julius("Julius Caesar");
	int space = julius.find(" ");

	string firstName = julius.substr(0, space);
	string lastName = julius.substr(space+1);

	cout << "First name: " << firstName << endl;
	cout << "Last name: " << lastName << endl;
}

