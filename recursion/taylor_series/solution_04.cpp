//space complexity -- O(1)
//time  complexity -- O(n)

#include <stdio.h>

double e(int x,int n)
{
	double sum = 1;
	double power = 1;
	double factorial = 1;

	for(int i=1 ; i <= n ; i++)
	{
		power *= x;
		factorial *= i;
		sum += power / factorial;
	}

	return sum; 
}

int main()
{
	printf("%lf\n",e(1,10));

	return 0;
}
