#include <iostream>
#include <iomanip>
#include <cstddef>
using namespace std;

/*
 *  byte is an enum class. A byte is only a collection of bits, and the only operators defined 
 *  for it are the bitwise operators. 
 */

ostream& operator<<(ostream& os, std::byte b)
{
	os << uppercase << hex << static_cast<unsigned int>(b);
	return os;
}

int main()
{
	byte b{0x41};
	char c;

	c = static_cast<unsigned char>(b);
	cout << "byte " << b << " = '" << c << "'" << endl;

	// assignment
    b = byte(2);
	cout << b << endl;

	// left shift
	b <<= 5;
	cout << b << endl;

	// binary literals
	byte byte1{ 0b00110011 };
	byte byte2{ 0b10101010 };
	cout << hex << byte1 << endl;
	cout << hex << byte2 << endl;

	// bit-wise OR and AND operations
	byte byteOr = byte1 | byte2;
	byte byteAnd = byte1 & byte2;
	cout << byteOr << endl;
	cout << byteAnd << endl;

	// int x = b;  // error: bytes can be cat to integral types
}
