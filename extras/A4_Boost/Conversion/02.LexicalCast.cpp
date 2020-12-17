////////////////////////////////////////////////////////////
//
//		Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
using namespace std;

int main()
{
	using boost::lexical_cast;
	using boost::bad_lexical_cast;

	vector<short> v;
	try {
		v.push_back(lexical_cast<short>(25));
		v.push_back(lexical_cast<short>(37));
		v.push_back(lexical_cast<short>(-15));
		v.push_back(lexical_cast<short>(25.67));
	} catch (bad_lexical_cast& e) {
		cout << "Exception caught - " << e.what() << endl;
	}

	for(unsigned i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
