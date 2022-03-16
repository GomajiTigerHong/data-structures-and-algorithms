//space complexity O(n)
//time complexity O(n)

#include <stdio.h>

int fact(int n)
{
	if(n==0)
	{
		return 1;
	}
	
	return fact(n-1)*n;
}

int main()
{
	printf("%d\n",fact(8));

	return 0;
}
