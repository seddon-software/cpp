////////////////////////////////////////////////////////////
//
//      Using the Heap
//
////////////////////////////////////////////////////////////

#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

void old_method()
{
    char* ptr1;
    ptr1 = (char*) malloc(sizeof(char)*4);
    strcpy(ptr1, "ABC");
    printf("%s\n", ptr1);
    free(ptr1);
    
    const int max = 10;
    int* array = (int*) malloc(sizeof(int) * max);
    
    for (int i = 0; i < max; i++)
    {
        array[i] = i * i;
        printf("Square of %i is %i\n", i, array[i]);
    }
    free(array);
}

void new_method()
{
    string* ptr1;
    ptr1 = new string("ABC");       // allocate with new
    cout << *ptr1 << endl;
    delete ptr1;                    // deallocate with delete

    const int max = 10;
    int* array = new int[max];      // allocate with new[]

    for (int i = 0; i < max; i++)   // deallocate with delete[]
    {
        array[i] = i * i;
        cout	<< "Square of " << i << " is " << array[i] << endl;
    }
    delete [ ] array;
}

int main()
{
	old_method();
    new_method();
}