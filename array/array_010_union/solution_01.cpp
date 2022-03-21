//Union space complexity -- O(n)
//Union time  complexity -- O(n)

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

struct Array * Union(struct Array * arr1 , struct Array * arr2)
{
	int arr1_index = 0 ;

	int arr2_index = 0 ;

	int arr3_index = 0 ;

	struct Array * arr3 = (struct Array *)malloc(sizeof(struct Array));

	while(arr1_index < arr1->length && arr2_index < arr2->length)
	{
		if(arr1->A[arr1_index] < arr2->A[arr2_index])
		{
			arr3->A[arr3_index++] = arr1->A[arr1_index++];
		}
		else if(arr2->A[arr2_index] < arr1->A[arr1_index])
		{
			arr3->A[arr3_index++] = arr2->A[arr2_index++];
		}
		else
		{
			arr3->A[arr3_index++] = arr1->A[arr1_index++];

			arr2_index++;
		}
	}

	for(;arr1_index < arr1->length ; arr1_index++)
	{
		arr3->A[arr3_index++] = arr1->A[arr1_index];
	}

	for(;arr2_index < arr2->length ; arr2_index++)
	{
		arr3->A[arr3_index++] = arr2->A[arr2_index];
	}

	arr3->length = arr3_index;

	arr3->size   = 87;

	return arr3;
}

int main()
{
	struct Array arr1 = {{1,2,3,4,5,6,7,8},20,8};
	
	struct Array arr2 = {{2,3,4,87},30,4};
	
	struct Array *arr3 = Union(&arr1,&arr2); 

	Display(*arr3);
	
	return 0;
}
