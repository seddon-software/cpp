////////////////////////////////////////////////////////////
//
//		Namespace Aliases
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/*  When nesting namespaces, notation can become very verbose.  To rectify this you can now set up
 *  aliases for namespaces as in:
 *		namespace oii = outer::inner::in;
 *
 *  Starting with C++17 you can replace the old way of nesting namespaces, viz:
 *		namespace outer {
 *			namespace inner {
 *				namespace in {
 *					int x = 110;
 *				}
 *			}
 *		}
 *  with the succinct version shown below:
 */

// C++17 version
namespace outer::inner::in
{
	int x = 110;
}

int main()
{
	cout << outer::inner::in::x << endl;
	namespace oii = outer::inner::in;
	cout << oii::x << endl;

	using namespace oii;
	cout << x << endl;
}
