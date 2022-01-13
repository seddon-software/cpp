//////////////////////////////////////////////////////////////////////
//
//		Placement new
//
//////////////////////////////////////////////////////////////////////

#include <new>
#include <string>
#include <iostream>
using namespace std;
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>

/*
 *  This example is very similar to the last one, except this time we use mmap and the Linux API to 
 *  write our objects to memory mapped files:
 * 	            ./mempool1
 *              ./mempool2
 * 
 *  You can find a lot of information about memory mapped files on the web, for example:
 *      http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2044.html
 * 
 *  I haven't included the Windows version of this example, but its not difficult to write.
 * 
 *  After the program finishes you can check the contents of the two binary files using the "hexdump"
 *  utility.
 */

template <typename T>
T* memoryAllocator(int fd, int size)
{
#if defined(WIN32)
#error example does not work on windows
#else
	ftruncate(fd, size);		    // make sure file is right size to map
	T* array = (T*) mmap(
			0, 	                    // void *addr,
			size,                   // size_t len,
			PROT_READ | PROT_WRITE, // int prot,
			MAP_SHARED,             // int flags,
			fd,                     // int fd,
			0                       // off_t offset);
			);
	close(fd);
	if(size_t(array) == -1) perror("MMAP");
	return array;
#endif
}

class Date
{
public:
	Date(int d, int m, int y) : day(d), month(m), year(y) {}
	~Date() {}

	void Display()
	{
		cout << "Date: " << day << "-" << month << "-" << year << endl;
	}

	static Date* AllocateMemory(int fd, int size)
	{
		ftruncate(fd, size);		// make sure file is right size to map
		Date* array = (Date*) mmap(
				0, 	                    // void *addr,
				size,                   // size_t len,
				PROT_READ | PROT_WRITE, // int prot,
				MAP_SHARED,             // int flags,
				fd,                     // int fd,
				0                       // off_t offset
				);
		close(fd);
		if(size_t(array) == (unsigned)-1) perror("MMAP");
		return array;
	}

	static void* operator new(size_t, void* address)
	{
		return address;
	}

private:
	int day;
	int month;
	int year;
};

class Point
{
public:
	Point(int x0, int y0) : x(x0),y(y0) {}
	~Point() {}
	
	void WhereAreYou()
	{
		cout << "Point is at: " << x << ", " << y << endl;
	}

	static Point* AllocateMemory(int fd, int size)
	{
		ftruncate(fd, size);		// make sure file is right size to map
		Point* array = (Point*) mmap(
			0, 	                    // void *addr,
			size,                   // size_t len,
			PROT_READ | PROT_WRITE, // int prot,
			MAP_SHARED,             // int flags,
			fd,                     // int fd,
			0                       // off_t offset
			);
		close(fd);
		if(size_t(array) == unsigned(-1)) perror("MMAP");
		return array;
	}

	// this is normally provided by the compiler (shown here for illustration only)
	static void* operator new(size_t, void* address)
	{
		return address;
	}

private:
	int x;
	int y;
};

/////

int createFile(const string& fileName)
{
	int fd = open(fileName.c_str(), O_RDWR|O_CREAT, 0x666);
	if(fd == -1) perror("OPEN");
	int rc = fchmod(fd, 0666);
	if(rc == -1) perror("CHMOD");
	return fd;
}

int main()
{
	// set up files for memory mapping
    umask(mode_t(0));
	int fd1 = createFile("./mempool1");
	int fd2 = createFile("./mempool2");

	// pre-allocate raw memory for objects
	Point* points = Point::AllocateMemory(fd1, 100 * sizeof(Point));  // space for 100 objects
	Date*  dates  = Date ::AllocateMemory(fd2, 100 * sizeof(Date));   // space for 100 objects

	// place objects in raw memory
	new (&points[0]) Point(10, 250);
	new (&points[1]) Point(11, 21);
	new (&points[2]) Point(12, 22);
	new (&points[3]) Point(13, 23);

	new (&dates[0]) Date(12,  8, 1999);
	new (&dates[1]) Date(22,  5, 2000);
	new (&dates[2]) Date(31,  1, 2001);
	new (&dates[3]) Date( 4, 11, 1999);

	// code to use shared memory objects ...
	for(int i = 0; i < 4; i++)
	{
		points[i].WhereAreYou();
		dates[i].Display();
	}

	// call DTORs for each object
	// objects are not on the heap so delete must not be called
	for(int i = 0; i < 4; i++)
	{
		points[i].~Point();
		dates[i].~Date();
	}
}
  
