//array linear research time complexity O(n)

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

void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;

	*y = temp;
}

int LinearSearch(struct Array *arr,int key)
{
	for(int i = 0; i < arr->length ; i++)
	{
		if(key == arr->A[i])
		{
			swap(&arr->A[i],&arr->A[0]);

			return i;
		}
	}

	return -1;
}

int main()
{
	struct Array arr = {{1,2,3,4,5,6,7,8},20,8};
	
	printf("%d\n",LinearSearch(&arr,3));

	Display(arr);
	
	return 0;
}
