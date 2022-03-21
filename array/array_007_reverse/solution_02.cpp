//Reverse time  complexity -- O(n)
//Reverse space complexity -- O(n)

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

void swap(int *x , int *y)
{
	int temp = *x;

	*x = *y;

	*y = temp;
}

void Reverse(struct Array *arr)
{
	for(int i = 0 ,j = arr->length - 1 ; i < j ; i++ , j--)
	{
		swap(&arr->A[i],&arr->A[j]);
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
