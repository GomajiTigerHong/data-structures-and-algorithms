//basic array implementation using c

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

int Delete(struct Array *arr,int index)
{
	if(index >= 0 && index < arr->length)
	{
		int x = arr->A[index];

		for(int i = index ; i < arr->length-1 ; i++)
		{
			arr->A[i] = arr->A[i+1];
		}
		
		arr->length --;

		return x;
	}

	return 0;
}


int main()
{
	struct Array arr = {{1,2,3,4,5,6,7,8},20,8};

	Display(arr);
	
	printf("%d\n",Delete(&arr,2));

	return 0;
}
