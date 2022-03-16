//space complexity O(1)
//time complexity O(n)

#include <stdio.h>

int sum(int n)
{
	int s = 0;

	for(int i = 0 ; i <= n ; i++)
	{
		s = s + i;
	}

	return s;
}

int main()
{
	printf("%d\n",sum(10));

	return 0;
}
