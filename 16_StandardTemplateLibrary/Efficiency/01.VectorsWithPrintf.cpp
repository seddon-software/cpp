#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
    vector<int> a = {2,3,5,7,11,13,17};

	for(int k =0; k < 100000; k++)
	{
		for_each(a.begin(), a.end(), [&](int x) {
			printf("%i,", x);
		});
		printf("\n");
	}
}

