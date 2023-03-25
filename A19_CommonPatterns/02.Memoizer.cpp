#include <iostream>
#include <map>
using namespace std;

/* 
 *  The memoizer pattern is used to speed up recursive algorithms.  Here we look at calculation of 
 *  Fibonacci numbers.  These calculations involve many recalculations of the same Fibonacci number
 *  for larger N.  This pattern avoids unnecessary recurses by caching previous calculations.
 * 
 *  The final output shows the Fibonacci number and the number of calls.  As N increases, the memoizer
 *  saves a huge number of recursive calls.
 */

int Fib_count = 0;
int fib_count = 0;

template <int(*f)(int)>
int memoize(int x)
{
    static std::map<int, int> cache;
    map<int, int>::iterator i = cache.find(x);

    // if answer is in the cache, return it
    if (i != cache.end()) return i->second;

    // otherwise add result to cache and return f(x)
    return cache[x] = f(x);
}

int fib(int n) {
    fib_count++;
	if (n < 2) return n;
	return memoize<fib>(n - 1) + memoize<fib>(n - 2);
}

int Fib(int n) {
    Fib_count++;
	if(n < 2) 
    {
        return n;
    }
	return Fib(n-1) + Fib(n-2);
}

int main()
{
	cout << "result = " << fib(20) << ": memoizer call count = " << fib_count << endl;
	cout << "result = " << Fib(20) << ": call count = " << Fib_count << endl;
}
