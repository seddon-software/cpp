#include <iostream>
using namespace std;

// genric template (not used)
void print_all(ostream& os) {}

// specialization on parameter pack
template <class T, class... Ts>
void print_all(ostream& os, T const& first, Ts const&... rest) {
    os << first;

    print_all(os, rest...);
// expands to:
//    print_all(cout, s),
//    print_all(cout, 100),
//    print_all(cout, "Goodbye"),
//    print_all(cout, 3.14159)
}

int main()
{
	string s("Hello");
    print_all(cout, s, 100, "Goodbye", 3.14159);
}
