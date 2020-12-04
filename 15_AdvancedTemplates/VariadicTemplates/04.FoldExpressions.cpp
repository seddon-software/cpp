#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template<typename T>
static void g(T t)
{
    cout << t << ",";
}

template<typename... Args>
static void unaryRightFold(Args... args) {
	// ( pack op ... ) expands to: ((pack<0> op pack<1>) op pack<2>) ...

    cout << endl << "Unary Right Fold: " << endl;
    cout         << "================= " << endl;

    (((g(2), g(4)), g(6)), g(8));
    cout << endl;
	(g(args) , ...);	// op=, pack=args
	cout << endl;
}

template<typename... Args>
static void binaryRightFold(Args... args) {
	// ( pack op ... op init )	expands to: (((init op pack<0>) op pack<1>) op pack<2>) ...

    cout << endl << "Binary Right Fold: " << endl;
    cout         << "================== " << endl;

// example 1
    ((((cout << 2) << 4) << 6) << 8) << endl;
    (cout << ... << args) << endl;	// init=cout, op=<<, pack=args

// example 2
    int sum = 0;
    sum = ((((sum + 2) + 4) + 6) + 8);
    cout << "sum= " << sum << endl;

    sum = 0;
    sum = (sum + ... + args);	        // init=sum, op=+, pack=args
    cout << "sum= "  << sum << endl;

}

int main() {
	string cyan("Cyan");
	unaryRightFold(100, 3.14159, "Red", cyan);
	binaryRightFold(2, 4, 6, 8);
}
