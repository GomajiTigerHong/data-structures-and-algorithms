//space complexity O(n)
//time complexity O(n)

#include <stdio.h>

int power(int base,int exponent)
{
	if(exponent==0)
	{
		return 1;
	}

	return power(base,exponent-1)*base;
}

int main()
{
	printf("%d\n",power(2,9));

	return 0;
}
