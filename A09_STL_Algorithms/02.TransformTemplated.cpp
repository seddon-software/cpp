#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/* 
 *  In this example we again use the transform algorithm, but this time via a template parameter pack,
 *  used to set initial values in a vector.  We will be passing both variables (l-value refs) and 
 *  constants (r-value refs) to the PushBack template and therefore must pass parameters by r-value 
 *  ref.  Recall, the collapsing rules mean that this with work for both types of references.
 * 
 *  The PushBack template works by using a right fold expression:
 *      (v.push_back(args), ...);   // fold using comma operator - brackets mandatory
 *  
 *  The call:
 *      Transform<int>(2, 4, 6, 8, z);
 *
 *  eventually invokes the right fold expression in the PushBack template. The fold expression 
 *  expands to:
 *      v.push_back(2), (v.push_back(4) ,(v.push_back(6), (v.push_back(8), v.push_back(z))));
 *
 *  You find it useful to paste this example into:
 *      https://cppinsights.io/
 * 
 *  to verify the fold expression expansions.
 */

template<typename T, typename... Args>
void PushBack(vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);   // fold using comma operator - brackets mandatory
}

template <typename T, typename... Args>
void Transform(T v0, Args&& ... args)
{
	vector<T> v;
	(v.push_back(args), ...);  // fold using comma operator - brackets mandatory
	vector<T> v2(v.size());
	transform(v.begin(), v.end(),
			v2.begin(),
			[](T x){ return x * x * x; });
	copy(v2.begin(), v2.end(), ostream_iterator<T>(cout, " "));
	cout << endl;
}

int main()
{
    int z{11};

	Transform<int>(2, 4, 6, 8, z);   // z is l-value ref, others are r-value refs
	Transform<double>(2.5, 3.5, 4.5, 5.5, 6.5, z);
}

