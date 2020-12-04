#include <iostream>
using namespace std;


template<class LHS, class RHS>
auto add(const LHS &lhs, const RHS &rhs) -> decltype(lhs+rhs)
{
	return lhs + rhs;
}


int main()
{
	auto result = add(5, 6.78);
	cout << result << endl;
}
