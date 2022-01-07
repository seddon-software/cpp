#ifndef TYPELIST_H_
#define TYPELIST_H_

////////////////////////////////////////////////////////////
// Typelist

// primary template (never used)
template <typename...Ts>		// takes 0 or more types
struct Typelist;

// specialization for empty Typelist
template <>
struct Typelist<>
{
    typedef void result;
};

// specialization for non empty Typelist
template <typename HEAD, typename...Ts>
struct Typelist<HEAD,Ts...>
{
    typedef Typelist<HEAD, typename Typelist<Ts...>::result> result;
};



////////////////////////////////////////////////////////////
// Length: length of a typelist

// primary template (never used)
template <typename TList> 
struct Length;		

// specialization for Typelist
template <typename HEAD,typename ...Ts>
struct Length<Typelist<HEAD,Ts...>>
{
	enum { value = 1 + Length<Typelist<Ts...>>::value };
};

// specialization for empty Typelist
template<>
struct Length<Typelist<>>
{
	enum { value = 0 };
};

////////////////////////////////////////////////////////////
// TypeAt: indexed access to typelists

// primary template (never used)
template<typename TList, int i> 
struct TypeAt;

// specialization for Typelist,0
template<typename HEAD, typename ...Ts>
struct TypeAt<Typelist<HEAD,Ts...>, 0>
{
	typedef HEAD result;
};

// specialization for Typelist,i
template<typename HEAD, typename ...Ts, int i>
struct TypeAt<Typelist<HEAD,Ts...>, i>
{
	typedef typename TypeAt<Typelist<Ts...>,i-1>::result result;
};

////////////////////////////////////////////////////////////
// IndexOf: searching typelists

// primary template (never used)
template<typename TList, typename T> struct IndexOf;

// specialization for case where Typelist is empty
template<typename T>
struct IndexOf<Typelist<>,T>
{
	enum { value = -1 };
};

// specialization for case where T is actually the Head
template<typename T, typename ...Ts>
struct IndexOf<Typelist<T,Ts...>,T>
{
	enum { value = 0 };
};

// specialization for all other Typelist cases
template<typename HEAD, typename ...Ts, typename T>
struct IndexOf<Typelist<HEAD,Ts...>,T>
{
private:
	// compute value for shorter list
	enum { temp = IndexOf<Typelist<Ts...>,T>::value };
public:
	// if we ended up with empty list return -1
	// otherwise add 1 for the head
	enum { value = temp == -1 ? temp : temp + 1 };
};





#endif /*TYPELIST_H_*/
