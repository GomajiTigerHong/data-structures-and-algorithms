//time  complexity -- O(n)
//space complexity -- 0(1)

#include <stdio.h>

struct Array
{
	int A[20];
	int size;
	int length;
};

void Display(struct Array arr)
{
	printf("\nElements are\n");
	
	for(int i = 0 ; i < arr.length ; i++)
	{
		printf("%d\n",arr.A[i]);
	}
}

int isSorted(struct Array arr)
{
	for(int i = 0 ; i < arr.length - 1 ; i++)
	{
		if(arr.A[i] > arr.A[i+1])
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	struct Array arr = {{1,2,3,4,5,6,7,8},20,8};

	Display(arr);
	
	printf("%d\n",isSorted(arr));

	struct Array arr1 = {{8,7,65,4,3,2},22,6};

	Display(arr1);

	printf("%d\n",isSorted(arr1));

	return 0;
}
