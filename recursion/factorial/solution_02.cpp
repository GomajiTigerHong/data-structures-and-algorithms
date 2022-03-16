//space complexity O(1)
//time complexity O(n)

#include <stdio.h>

int fact(int n)
{
	int sum = 1;

	for(int i = 1 ; i <= n ; i++)
	{
		sum = sum * i;
	}

	return sum;
}

int main()
{
	printf("%d\n",fact(8));

	return 0;
}
