#include <stdio.h>
#include <string.h>

#define DATA_ROWS 7
#define DATA_COLS 2
#define ARGUMENT_COUNT 2

int CheckDataType(int data);
void ConvertData(int data[DATA_ROWS][DATA_COLS], char *argv[]);
void PrintData(int data[DATA_ROWS][DATA_COLS]);

int main(int argc, char *argv[])
{
    if (argc != ARGUMENT_COUNT)
	{
		printf("ERROR: Argument count must be two!");
		return 0;
	}
	
    int mixedData[DATA_ROWS][DATA_COLS] = {
        {1300, 0},
        {2198, 0},
        {4199, 1},
        {2103, 0},
        {3104, 1},
        {1093, 1},
        {3204, 0}};
    
    ConvertData(mixedData, argv);
    PrintData(mixedData);
    
    return 0;
}
int CheckDataType(int data)
{
	
	if (data == 0 )
	{
		return 0;
	}
	else 
	{
		return 1;
	}
	
}
void ConvertData(int data[DATA_ROWS][DATA_COLS], char *argv[])
{
	int i;
	
	if (strcmp(argv[1], "ft") == 0)
	{
		for (i = 0; i < DATA_ROWS; i++)
		{
			if (CheckDataType(data[i][1]) == 0)
			{
				data[i][0] = 0.3048 * data[i][0];	
			}
		}
	}
	else if (strcmp(argv[1], "m") == 0)
	{
		for (i = 0; i < DATA_ROWS; i++)
		{
			if (CheckDataType(data[i][1]) == 1)
			{
				data[i][0] = data[i][0] / 0.3048;	
			}
		}
	}
}
void PrintData(int data[DATA_ROWS][DATA_COLS])
{
	int totalDistance = 0, i;
	
	for (i = 0; i < DATA_ROWS; i++)
	{
		printf("the distance walked by employee number %d is %d\n", i+1 , data[i][0]);
	}
	for (i = 0; i < DATA_ROWS; i++)
	{
		totalDistance += data[i][0]; 
	}
	printf("the average distance is %d\n", totalDistance / DATA_ROWS );
	printf("the total distance is %d\n", totalDistance);
	
	
}
