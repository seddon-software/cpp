#include <iostream>
#include <vector>
#include <numeric>      //std::iota to generate sequence of integer
#include <algorithm>
#include <iterator>

/*  
 *  The stable_partition algorithm splits a collection (e.g. vector) into two parts dependent on a filter
 *  defined by a lambda (or function pointer).  Unlike the partition algorithm, stable_partition is 
 *  guaranteed to preserve order of the original collection.
 */

using namespace std;

int main()
{
    vector<int> v(20);
    iota(begin(v), end(v), 0); // 0, 1, 2, ... 19

    cout << boolalpha;
    // lambda to calculate even numbers
    auto evenOdd = [](const int& i){ return i%2 == 0; };

    // partition vector into odd and even numbers
    stable_partition(v.begin(), v.end(), evenOdd);
    cout << "is vector_partitioned? " 
         << is_partitioned(v.begin(), v.end(), evenOdd) << endl;

    // find partition point (iterator)
    auto partitionPoint = partition_point(v.begin(), v.end(), evenOdd);

    cout << "begin to partition point" << endl;
    copy(v.begin(), partitionPoint, ostream_iterator<int>(cout, ", "));
	cout << endl;

    cout << "partition point to end" << endl;
    copy(partitionPoint, v.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
}
