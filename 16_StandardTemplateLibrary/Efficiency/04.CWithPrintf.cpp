#include <stdio.h>


int main()
{
	int a[7] = {2,3,5,7,11,13,17};
	for(int k =0; k < 100000; k++)
	{
		for(int i = 0; i < 7; i++)
		{
				printf("%i,", a[i]);
		}
		printf("\n");
	}
}

