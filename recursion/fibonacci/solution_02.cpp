//space complexity -- O(1)
//time  complexity -- O(n)

#include <stdio.h>

int fib(int n)
{
	int first = 0;

	int second = 1;

	int sum = 0;

	if(n <= 1)
	{
		return n;
	}

	for(int i = 2; i <= n ; i++)
	{
		sum = first + second;
		first = second;
		second = sum;
	}

	return sum;
}

int main()
{
	printf("%d\n",fib(10));

	return 0;
}
