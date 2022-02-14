#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	DIGIT 10

int ReturnNums(int numArray[]);
void FindCommon(int numArray[]);
void FindBiggestAndSmallest(int numArray[]);
int main (void)
{

	int numArray[DIGIT] = { 0 };

	if (ReturnNums(numArray) == 1)
	{
		printf("Exit, Error opening file\n");
		exit(EXIT_FAILURE);
	}
	FindCommon(numArray);
	FindBiggestAndSmallest(numArray);
	return 0;
}

int ReturnNums(int numArray[])
{
	int num = 0;
	
	FILE *fInput;
	
	fInput = fopen("data1.txt", "r");
	
	if (fInput == NULL)
	{
		fclose(fInput);
		return 1;
	}
	

	while(fscanf(fInput,"%d", &num) != EOF)
	{
		switch(num)
		{
			case 0:
				numArray[0]++;
				break;
			case 1:
				numArray[1]++;
				break;
			case 2:
				numArray[2]++;
				break;
			case 3:
				numArray[3]++;
				break;
			case 4:
				numArray[4]++;
				break;
			case 5:
				numArray[5]++;
				break;
			case 6:
				numArray[6]++;
				break;
			case 7:
				numArray[7]++;
				break;
			case 8:
				numArray[8]++;
				break;
			case 9:
				numArray[9]++;
				break;
		}
	}
	fclose(fInput);
	return 0;
}




void FindCommon(int numArray[])
{
	int i;
	for (i = 0; i < DIGIT; i++)
	{
		printf("Number %d occured %d time(s)", i, numArray[i]);
		if (numArray[i] > 1)
		{
			printf("	COMMON VALUE");
		}
		puts("\n");
	}
	
}
void FindBiggestAndSmallest(int numArray[])
{
	int i;
	int small = 9 , big = 0;
	for (i = 0; i < DIGIT; i++)
	{
		if (numArray[i] > 0)
		{
			if (i < small)
			{
				small = i;
			}
			if (big < i)
			{
				big = i;
			}
		}
	}
	printf("Lowest value: %d\n", small);
	printf("Highest value: %d\n", big);
}
