#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

void f1() {}
void f2() noexcept {}

/////

int main()
{
	auto g1 = [](){};
	auto g2 = []() noexcept {};

	cout << std::boolalpha << "can f1() throw? " << noexcept(f1()) << endl;
	cout << std::boolalpha << "can f2() throw? " << noexcept(f2()) << endl;
	cout << std::boolalpha << "can g1() throw? " << noexcept(g1()) << endl;
	cout << std::boolalpha << "can g2() throw? " << noexcept(g2()) << endl;
}
