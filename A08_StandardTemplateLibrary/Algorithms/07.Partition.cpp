#include <iostream>
#include <vector>
#include <numeric> //std::iota
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v(20);
    iota(begin(v), end(v), 0); // 0, 1, 2, ... 19

    cout << boolalpha;
    // lambda to calculate even numbers
    auto evenOdd = [](const int& i){ return i%2 == 0; };

    // partition vector into odd and even numbers
    partition(v.begin(), v.end(), evenOdd);
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
