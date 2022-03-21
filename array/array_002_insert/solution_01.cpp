//array append time complexity -- O(1)
//array insert time complexity -- O(n)

#include <stdio.h>

struct Array
{
	int A[10];
	int size;
	int length;
};

void Display(struct Array arr)
{
	printf("\nElements are\n");
	
	for(int i = 0;i < arr.length ; i++)
	{
		printf("%d\n",arr.A[i]);
	}

	printf("Array length = %d\n",arr.length);

	printf("Array size = %d\n",arr.size);
}

void Append(struct Array *arr,int x)
{
	if(arr->length < arr->size)
	{
		arr->A[arr->length++] = x;
	}
}

void Insert(struct Array *arr,int index,int x)
{
	if(index >=0 && index <= arr->length)
	{
		for(int i = arr->length; i > index ; i--)
		{
			arr->A[i] = arr->A[i-1];
		}
	arr->A[index] = x;
	
	arr->length++;
	}
}

int main()
{
	struct Array arr = {{1,2,3,4,5,6},87,6};
	
	Display(arr);

	Append(&arr,10);
	
	Display(arr);

	Insert(&arr,0,12);

	Display(arr);

	return 0;
}
