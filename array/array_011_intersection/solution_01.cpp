//Intersection space complexity -- O(n)
//Intersection time  complexity -- O(n)

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

struct Array * Intersection(struct Array *arr1,struct Array *arr2)
{
	int arr1_index = 0;

	int arr2_index = 0;

	int arr3_index = 0;

	struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

	while(arr1_index < arr1->length && arr2_index < arr2->length)
	{
		if(arr1->A[arr1_index] < arr2->A[arr2_index])
		{
			arr1_index++;
		}
		else if(arr2->A[arr2_index] < arr1->A[arr1_index])
		{
			arr2_index++;
		}
		else if(arr1->A[arr1_index] == arr2->A[arr2_index])
		{
			arr3->A[arr3_index++] = arr1->A[arr1_index++];

			arr2_index++;
		}
	}

	arr3->length = arr3_index;

	arr3->size = 76;

	return arr3;
}

int main()
{
	struct Array arr1 = {{1,2,3,4,5,6,7,8},20,8};

	struct Array arr2 = {{2,3,8,100,101},22,5};

	struct Array *arr3 = Intersection(&arr1,&arr2);

	Display(*arr3);
	
	return 0;
}
