/* 
 *  The noexcept clause is important when it comes to exception safety.  But did you know it is
 *  possible to enquire if a function throws exceptions(see below):
 */

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

auto f1 = []() { throw exception(); };
auto f2 = []() noexcept {};
//	auto f3 = []() noexcept { throw Exception(); };  // doesn't compile

/////

int main()
{
	auto g1 = []() { throw exception(); };
	auto g2 = []() noexcept {};
//	auto g3 = []() noexcept { throw Exception(); };  // doesn't compile

	cout << std::boolalpha << "can f1() throw? " << !noexcept(f1()) << endl;
	cout << std::boolalpha << "can f2() throw? " << !noexcept(f2()) << endl;
	cout << std::boolalpha << "can g1() throw? " << !noexcept(g1()) << endl;
	cout << std::boolalpha << "can g2() throw? " << !noexcept(g2()) << endl;
}
