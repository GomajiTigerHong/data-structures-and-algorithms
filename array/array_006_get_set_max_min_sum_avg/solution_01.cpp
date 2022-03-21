//Get time complexity -- O(1)
//Set time complexity -- O(1)
//Max time complexity -- 0(n)
//Min time complexity -- O(n)
//Sum time complexity -- O(n)
//Avg time complexity -- O(n)

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

int Get(struct Array arr,int index)
{
	if(index >= 0 && index < arr.length)
	{
		return arr.A[index];
	}

	return -1;
}

void Set(struct Array *arr,int index,int value)
{
	if(index >= 0 && index < arr->length)
	{
		arr->A[index] = value;
	}
}

int Max(struct Array arr)
{
	int max = arr.A[0];

	for(int i = 0 ; i < arr.length ; i++)
	{
		if(arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}

	return max;
}

int Min(struct Array arr)
{
	int min = arr.A[0];

	for(int i = 0 ; i < arr.length ; i++)
	{
		if(arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}

	return min;
}

int Sum(struct Array arr)
{
	int sum = 0;

	for(int i = 0 ; i < arr.length ; i++)
	{
		sum = sum + arr.A[i];
	}

	return sum;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr)/arr.length;
}

int main()
{
	struct Array arr = {{1,2,3,4,5,6,7,8},20,8};
	
	printf("%d\n",Get(arr,4));
	
	Display(arr);

	Set(&arr,3,100);

	Display(arr);

	printf("%d\n",Max(arr));

	printf("%d\n",Min(arr));

	printf("%d\n",Sum(arr));

	printf("%lf\n",Avg(arr));
	
	return 0;
}
