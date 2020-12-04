///////////////////////////////////////////////////////////////
//
//		Iterator
//
///////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class OutOfBounds {};

template <typename T>
class Collection
{
public:
    enum { Max = 10 };
	class Iterator
	{
	// collection needs to access iterator::setCollection
	// and method is private to hide it from users
	friend class Collection;

	public:
		Iterator() : position(0), pCollection(0) {}
		void next() throw(OutOfBounds)
		{
			if(position == Max - 1) throw OutOfBounds();
			position++;
		}
		void previous() throw(OutOfBounds)
		{ 
			if(position == 0) throw OutOfBounds();
			position--; 
		}
		T get()
		{
			return pCollection->array[position];
		}
	private:
		void setCollection(Collection* pc)
		{
			pCollection = pc;
		}

		int position;
		Collection* pCollection;
	};

public:
	Collection() : iterator() , size(0)
	{
		iterator.setCollection(this);
	}
    void Add(T t)
    {
        if(size == Max) throw OutOfBounds();
        array[size] = t;
        size++;
    }
	Iterator& getIterator()
	{
		return iterator;
	}
private:
    int size;
	T array[Max];
	Iterator iterator;
};



int main()
{
	try
	{
	    Collection<int> myList;
	    Collection<int>::Iterator myIterator;
    	
        myList.Add(2);
        myList.Add(3);
        myList.Add(5);
        myList.Add(7);
        myList.Add(11);
        myList.Add(13);
        myList.Add(17);
        myList.Add(19);
        myList.Add(23);
        myList.Add(27);

        myIterator = myList.getIterator();
	
		int result;
		while(true)
		{
			result = myIterator.get();
			cout << "item: " << result << endl;
			myIterator.next();
		}
	}
	catch(OutOfBounds)
	{
		cout << "Out of bounds" << endl;
	}
}
