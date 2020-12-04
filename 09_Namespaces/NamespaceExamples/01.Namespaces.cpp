////////////////////////////////////////////////////////////
//
//		Namespaces
//
////////////////////////////////////////////////////////////

namespace Geography
{
	class Map
	{
	public:
		void Draw() {}
	};

	class List
	{
	public:
		void Insert() {}
	};
}

namespace Maths
{
	class Map
	{
	public:
		void Clear() {}
	};

	class List
	{
	public:
		void Insert() {}
	};
}

/////

void f1()
{
	using namespace Geography;

	Map 			theWorld;		// using namespace Geography
	Maths::Map		theNumbers; 	// explicit

	theWorld.Draw();
	theNumbers.Clear();
}

void f2()
{
	using namespace Geography;
	using Maths::List;

	Map 			theWorld;		// using namespace Geography
	Maths::Map		theNumbers; 	// explicit
	Geography::List theCountries;	// explicit
	List			theSequences;	// using Maths::List

	theWorld.Draw();
	theNumbers.Clear();
	theCountries.Insert();
	theSequences.Insert();
}

int main()
{
	f1();
	f2();

	return 0;
}


