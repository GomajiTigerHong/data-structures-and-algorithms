//space complexity -- O(n)
//time  complexity -- O(n)

#include <stdio.h>

int fact(int n)
{
	if(n==0)
	{
		return 1;
	}
	
	return fact(n-1)*n;
}

int combination(int n,int r)
{
	int numerator;

	int denominator;

	numerator = fact(n);

	denominator = fact(r) * fact(n-r);

	return numerator/denominator;
}

int main()
{
	printf("%d\n",combination(4,2));

	return 0;
}
