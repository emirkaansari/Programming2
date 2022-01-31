#include <stdio.h>

#define MAX_LENGHT 10

int ReadVal(int arr[]);
void PrintAddress (int arr[],int len);
void FindMinMax (int arr[],int *min, int *max, int len);
void TaskTwoFunction(int arr[], int selection);


int main (void)
{
	int min = 0, max = 0;
	int arr[MAX_LENGHT];
	int lenght = ReadVal(arr);
	PrintAddress(arr, lenght);
	FindMinMax(arr, &min, &max, lenght);
	printf("minimum of array is : %d\n",min);
	printf("maximum of array is : %d\n",max);
	
	TaskTwoFunction(arr, 1);
	printf("-------------------\n");
	TaskTwoFunction(arr, 2);
	printf("-------------------\n");
	TaskTwoFunction(arr, 3);
	
	
	
	return 0;
}
int ReadVal(int arr[])
{
	int *p;
	p = arr;
	int i = 0, len;
	printf("Enter the count of numbers:\n");
	scanf("%d", &len);
	printf("Enter the numbers:\n");
	
	while (i < len)
	{
		scanf("%d", (p + i));
		i++;
	}
	
	return len;
}
void PrintAddress(int arr[],int len)
{
	int i;
	int *p;
	p = arr;
	for (i = 0; i < len; i++)
	{
		printf("address of the number is %p, value of the number is %d \n", (p+i), *(p+i));
	}
	
}
void FindMinMax (int arr[],int *min, int *max, int len)
{
	int i;
	int *p = arr;
	*min = *max = *p;
	for (i = 0; i < len; i++)
	{
		if (*min > *(p + i))
		{
			*min = *(p + i);
		}
		if (*max < *(p + i))
		{
			*max = *(p + i);
		}
	}
	
}
void TaskTwoFunction(int arr[], int selection)
{
	int i;
	int *p = arr;
	
	if (selection == 1)
	{
		PrintAddress(arr, MAX_LENGHT);
	}
	if (selection == 2)
	{
		for (i = 0; i < 5; i++)
		{
			printf("address of the number is %p, value of the number is %d \n", (p+i), *(p+i));
		}
	}
	if (selection == 3)
	{
		for (i = 3; i < 10; i++)
		{
			printf("address of the number is %p, value of the number is %d \n", (p+i), *(p+i));
		}
	}
	
	
	
}
