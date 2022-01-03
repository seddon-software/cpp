#include <iostream>
using namespace std;

/* 
 *  In addition to closures, lambdas can take parameters.  These are self explanatory.  Several
 *  examples are given below.  Note we are taking advantage of the new return type specification
 *  (e.g. -> int) with these examples.  Some programmer like to space their lambdas out over several
 *  lines whilst others are more succinct with their code.
 */ 

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
			 }(10, 200);    cout << result << endl;
    result = [](int x, int y) // auto return (c++17)
			 {
			     return x + y;
			 }(10, 200);    cout << result << endl;
}
