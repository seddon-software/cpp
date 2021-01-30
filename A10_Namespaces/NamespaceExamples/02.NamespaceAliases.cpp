////////////////////////////////////////////////////////////
//
//		Namespace Aliases
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

namespace outer {
	namespace inner {
		namespace in {
			int x = 110;
		}
	}
}

int main() 
{
	cout << outer::inner::in::x << endl;
	namespace oii = outer::inner::in;
	cout << oii::x << endl;
	
	using namespace oii;
	cout << x << endl;
}
