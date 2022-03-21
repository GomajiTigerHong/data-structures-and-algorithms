//time complexity O(logn)

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

int BinarySearch(struct Array arr,int key)
{
	int low = 0;

	int mid;

	int high = arr.length;

	while(low <= high)
	{
		mid = (low+high)/2;

		if(key == arr.A[mid])
		{
			return mid;
		}
		else if(key < arr.A[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return -1;
}


int main()
{
	struct Array arr = {{1,2,3,4,5,6,7,8},20,8};
	
	printf("%d\n",BinarySearch(arr,8));

	Display(arr);
	
	return 0;
}
