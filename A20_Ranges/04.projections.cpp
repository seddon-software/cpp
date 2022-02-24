#include <vector>
#include <ranges>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 *  In this example we use the std::ranges::sort template.  This template has 3 parameters:
 *          sort(Range range, Comparator comparator, Projection projection)
 * 
 *  Since all STL collection classes are ranges, we can use a vector for the first parameter.
 *  The send parameter, the comparitor defaults to ranges::less.  We use brace initialization {} to create 
 *  a default constructed comparator of this type.
 *  
 *  Finally, the last parameter is a projection; essentially a lambda that is applied to each item in the range.
 *  By using abs() we will sort the integers ignoring their sign.
 */

int main()
{
    std::vector v { -1, 5, -2, -7, 4, -9 };
    auto print = [](int i) { std::cout << i << ", "; };
    std::cout << "std::ranges::sort with comparator = ranges::less, projection = abs():" << endl;

    // {} is brace initialization: creates a default constructed ranges::less object
    std::ranges::sort(v, {}, [](int i) { return std::abs(i); }); 
    std::ranges::for_each(v, print);
    cout << endl;
}
