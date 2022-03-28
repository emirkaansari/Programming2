#include <stdio.h>

#include "recsursion.h"
int main(void)
{
	int a,b;
	int option = 1;
	
	while(option != 0)
	{
		printf("1)Find the sum of all positive integers leading to the number given.\n2)Find X^Y\n3)Find n-th Fibonacci number\n0)Quit\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
				printf("Enter a positive integer to find sum\n");
				scanf("%d",&a);
				printf("Sum of all positive intergers leading to %d is %d\n",a,findSum(a));
				break;
			case 2:
				printf("Find X^Y:\n Enter X= ");
				scanf("%d",&a);
				printf("Enter Y= ");
				scanf("%d",&b);
				printf("%d^%d= %d\n",a,b,findPower(a,b));
				break;
			case 3:
				printf("n:");
				scanf("%d",&a);
				printf("%d-th Fibonacci number is: %d\n",a,findFibonacci(a));
			case 0:
				continue;
		}
	}
	return 0;
}
int findSum(int n)
{
	if(n == 1)
	{
		return 1;
	}
	if( n == 0|| n < 0)
	{
		return 0;
	}
	return n + findSum(n - 1);
}
int findPower(int x, int y)
{
	if(y == 0)
	{
		return 1;
	}
	if(x == 0)
	{
		return 0;
	}
	if(y == 1)
	{
		return x;
	}
	return x * findPower(x, y - 1);
}
int findFibonacci(int n)
{
	if( n <= 1)
	{
		return 0;
	}
	if( n == 2)
	{
		return 1;
	}
	return findFibonacci(n - 1)+findFibonacci(n - 2);
}
