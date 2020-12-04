////////////////////////////////////////////////////////////
//
//		Policy Classes
//
////////////////////////////////////////////////////////////

#include <cstdlib>
using namespace std;

//////////////////////////////////////////////////
// Creator Policy: 
//	template<typename T>
//	class T
//	{
//		T Create();
//	};

template<typename T>
class OperatorNewPolicy
{
public:
	static T* Create()
	{
		return new T;
	}
};

template<typename T>
class MallocPolicy
{
public:
	static T* Create()
	{
		void* buffer = malloc(sizeof(T));
		if(!buffer) 
			return 0;
		else
			return new(buffer) T;
	}
};

template<typename T>
class PrototypePolicy
{
private:
	T* pPrototype;
public:
	PrototypePolicy(T* pObject = 0)
		: pPrototype(pObject)
	{}
	
	T* Create()
	{
		void* buffer = malloc(sizeof(T));
		if(!buffer) 
			return 0;
		else
			return new(buffer) T;
	}
	
	T* GetPrototype()
	{
		return pPrototype;
	}
	
	void SetPrototype(T* pObject)
	{
		pPrototype = pObject;
	}
};

////////////////////////////////////////////////////////////

// Define Library code that uses policy classes

	class Widget 
	{
	public:
		void f() {}
	};

	// 1) simple approach - makes client code more complicated
	template <class CreationPolicy>
	class Manager1 : public CreationPolicy
	{
	};
	
	// 2) add complexity to template definition to simplify client code
	template <
		template <typename Object> 
		class CreationPolicy
	>
	class Manager2 : public CreationPolicy<Widget>
	{
	};


/////


int main()
{
	// client chooses from 3 possible policies -> OperatorNewPolicy

	// first library template is complicated to use
	Manager1< OperatorNewPolicy<Widget> > manager1;
	Widget* myWidget1 = manager1.Create();
	myWidget1->f();
	
	// second library template is simpler
	Manager2<OperatorNewPolicy> manager2;
	Widget* myWidget2 = manager2.Create();
	myWidget2->f();
	
	return 0;
}

