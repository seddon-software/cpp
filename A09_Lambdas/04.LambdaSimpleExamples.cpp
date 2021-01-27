#include <iostream>
using namespace std;



int main()
{
	int result = 0;
	auto fp1 = [](int x, int y, int z) { return x + y + z; };
	auto fp2 =
			[](int x, int y) -> int
			{
				return x + y;
			};

	result = fp1(1, 2, 3);	cout << result << endl;
	result = fp2(10, 20);	cout << result << endl;
    result = [](int x, int y) -> int
			 {
			     return x + y;
			 }(10, 200);
	return 0;
}
