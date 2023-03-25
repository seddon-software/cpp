#include <iostream>
#include <vector>

namespace std
{
template<>
	void vector<int>::clear() noexcept
	{
		std::cout << "Clearing..." << std::endl;
		resize(0);
	}
}


int main()
{
	std::vector<int> v;
	v.push_back(1);
	v.clear();
}

