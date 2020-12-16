#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////
// Function argument lists
template <typename ...Ts>
void fa(Ts ...args) { cout << __PRETTY_FUNCTION__  << endl; }

template <typename ...Ts>
void expansionA(Ts ...args)
{
	// Function argument lists
	fa(args...);
}

////////////////////////////////////////////////////////////
// Parenthesized initializers
struct X
{
	template <typename ...Ts>
	X(Ts ...args) { cout << __PRETTY_FUNCTION__  << endl; }
};

template <typename ...Ts>
void expansionB(Ts ...args)
{
	__attribute__((unused))
	X x(args...);
}

////////////////////////////////////////////////////////////
// Brace-enclosed initializers
template <typename ...Ts>
void expansionC(Ts ...args)
{
	int array[] = {0, args...};
	for(auto a:array) cout << a << ","; cout << endl;
}

////////////////////////////////////////////////////////////
// Lambda captures
template <typename ...Ts>
void fd(Ts ...args) { cout << __PRETTY_FUNCTION__  << endl; }

template<typename ...Ts>
void expansionD(Ts... args) {
    auto lambda = [&, args...] { return fd(args...); };
    lambda();
}

////////////////////////////////////////////////////////////
// sizeof operator
template<typename... Types>
struct Y {
    static const std::size_t value = sizeof...(Types);
};
template<typename ...Ts>
void expansionE(Ts... args) {
    Y<Ts...> t{};
    cout << t.value << endl;
}

////////////////////////////////////////////////////////////
//
int main()
{
	string cyan("Cyan");
	expansionA(100, 3.14159, "Red", cyan);
	expansionB(100, 3.14159, "Red", cyan);
	expansionC(100, 200, 300);				// all same type
	expansionD(100, 3.14159, "Red", cyan);
	expansionE(100, 3.14159, "Red", cyan);
}
