//space complexity -- O(n)
//time  complexity -- O(2^n)

#include <stdio.h>

int combination(int n,int r)
{
	if(n==r || r==0)
	{
		return 1;
	}

	return combination(n-1,r-1) + combination(n-1,r);
}

int main()
{
	printf("%d\n",combination(4,2));

	return 0;
}
