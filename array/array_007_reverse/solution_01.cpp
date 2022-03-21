//Reverse time  complexity -- O(n)
//Reverse space complexity -- O(n)

#include <stdio.h>
#include <stdlib.h>

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

void Reverse(struct Array *arr)
{
	int *B ;//pointer(stack) to new array on heap

	B = (int *)malloc(arr->length * sizeof(int));

	for(int i = arr->length - 1, j = 0 ; i >= 0 ; i-- , j++)
	{
		B[j] = arr->A[i];
	}

	for(int i = 0 ; i < arr->length ; i++)
	{
		arr->A[i] = B[i];
	}
}

int main()
{
	struct Array arr = {{1,2,3,4,5,6,7,8},20,8};

	Display(arr);
	
	Reverse(&arr);

	Display(arr);
	return 0;
}
