//spcae complexity O(n)
//time complexity O(2^n)

//e^x = 1 + x/1! + x^2/2! + x^3/3! + ... + until n terms

#include <stdio.h>

double e(int x , int n)
{
	static double power = 1;

	static double factorial = 1;

	double sum;

	if(n==0)
	{
		return 1;
	}

	sum = e(x,n-1);

	power = power * x;

	factorial = factorial * n;

	return sum + power/factorial;
}

int main()
{
	printf("%lf\n",e(1,10));

	return 0;
}
