#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

/*
 *  views are a mapping on a range.  The view can be transformed without modifying the underlying range.
 *  Furthermore, whatever transformation they apply, the transformation is applied at the moment you request 
 *  an element from the view and not when the view is created.  Thus views employ lazy evalution of 
 *  transformations.
 * 
 *  Here, we create a reverse view on a vector.  Note that the underlying range is unaffected by the 
 *  reverse transformation.
 */

void print(auto v)
{
    for (auto i: v) cout << i << ",";
    cout << endl;
}

int main()
{
    vector v1{1, 2, 3, 4, 5, 6};
    auto v2 = std::views::reverse(v1);
    print(v1);
    print(v2);
}