//space complexity O(logn)
//time complexity O(logn)

#include <stdio.h>

int power(int base,int exponent)
{
	if(exponent==0)
	{
		return 1;
	}
	if(exponent%2 == 0)
	{
		return power(base*base,exponent/2);
	}

	return base*power(base*base,(exponent-1)/2);
}

int main()
{
	printf("%d\n",power(2,9));

	return 0;
}
