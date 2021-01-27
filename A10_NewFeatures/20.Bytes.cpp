#include <iostream>
#include <iomanip>
#include <cstddef>
using namespace std;

/*
 *
 */

ostream& operator<<(ostream& os, std::byte b)
{
	os << uppercase << hex << static_cast<unsigned int>(b);
	return os;
}

int main()
{
	std::byte b{0x41};
	char c;

	c = static_cast<unsigned char>(b);
	cout << "byte " << b << " = '" << c << "'" << endl;

	// assignment
    b = byte(2);
	cout << b << endl;

	// 2-bit left shift
	b <<= 2;
	cout << b << endl;

	// binary literals
	byte byte1{ 0b0011 };
	byte byte2{ 0b1010 };
	cout << byte1 << endl;
	cout << byte2 << endl;

	// bit-wise OR and AND operations
	byte byteOr = byte1 | byte2;
	byte byteAnd = byte1 & byte2;
	cout << byteOr << endl;
	cout << byteAnd << endl;
}
