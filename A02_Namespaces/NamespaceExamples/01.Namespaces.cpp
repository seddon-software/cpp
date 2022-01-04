////////////////////////////////////////////////////////////
//
//		Namespaces
//
////////////////////////////////////////////////////////////

/* 
 *  Namespaces are used to group entities like classes, objects and functions under a distinct name. 
 *  This allows the global scope to be divided in "sub-scopes", each one with its own name.  Namespaces
 *  are especially useful when a program uses two or more libraries and there is a possibility of name 
 *  clashes between the libraries.
 * 
 *  Different namespaces can be defined in the same file, but often there will be only one namespace 
 *  defined in a given file.  For larger libraries it is also possible for the namespace to span several
 *  files; each having the same namespace declaration.  These definitions are additive.
 * 
 *  Note: using namespace is used to tell the compiler to automatically search for a name in the given
 *  namespace.  It does not mean that other namespaces are ignored.  If more than one using namespace 
 *  statement is used then all such namespaces, plus the global namespace are searched for names.  
 *  Namespaces are scoped like other C++ entities.
 * 
 *  It is also possible to be explicit in which namespace to use when declaring an object.  This 
 *  overrides using namespace directives.
 
 
 */ 

// define 2 separate namespaces, both with Map and List classes.
namespace Geography
{
	class Map
	{
	public:
		void draw() {}
	};

	class List
	{
	public:
		void insert() {}
	};
}

namespace Maths
{
	class Map
	{
	public:
		void clear() {}
	};

	class List
	{
	public:
		void insert() {}
	};
}

/////

void f1()
{
	using namespace Geography;      // search this namespace and the global namespace

	Map theWorld;					// implicit, found in namespace Geography
	theWorld.draw();

    // be explicit in which namespace to search (others are ignored)
	Maths::Map theNumbers;		  	// explicit (overrides using namespace Geography)
	theNumbers.clear();
}

void f2()
{
	using namespace Geography;
	using Maths::List;

	Map theWorld;					// implicit, found in namespace Geography
	theWorld.draw();

	Maths::Map theNumbers;		 	// explicit (overrides "using namespace Geography")
	theNumbers.clear();

	Geography::List theCountries;	// explicit (overrides "using Maths::List")
	theCountries.insert();			// Geography::insert()

	List theSequences;				// implicit, so "using Maths::List"
	theSequences.insert();          // Maths::insert()
}

int main()
{
	f1();
	f2();
}


