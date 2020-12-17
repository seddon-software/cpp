#include <iostream>
#include <map>
using namespace std;

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
	if (n < 2) return n;
	return memoize<fib>(n - 1) + memoize<fib>(n - 2);
}

int main()
{
	cout << fib(20) << endl;
}
