#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LEN_NAME 32
#define MAX_READ 200
#define NUM_OF_VARIABLES 4
typedef struct people
{
	long id;
	char name[LEN_NAME];
	char surname[LEN_NAME];
	char city[LEN_NAME];
} people;
void OpenFile(people person[]);
void SortSurname(people person[], int lenght);
void PrintData(people person[], int lenght);
void SearchNames(people person[], int lenght);
int CheckCheckSum(long x);
int main(void)
{
	people person[MAX_READ];
	int lenght;
	
	OpenFile(person);
	lenght = sizeof(person) / sizeof(people);
	SortSurname(person, lenght);
	PrintData(person, lenght);
	SearchNames(person, lenght);
	exit(EXIT_SUCCESS);
}
void OpenFile(people person[])
{
	FILE *fInput;
	fInput = fopen("task1data.txt", "r");
	int i = 0;
	
	if(fInput == NULL)
	{
		printf("Error opening the file\n");
		exit(EXIT_FAILURE);	
	}
	while (fscanf(fInput,"%ld %s %s %s",&person[i].id, person[i].name,person[i].surname, person[i].city) == NUM_OF_VARIABLES)
	{
		i++;
	}
	fclose(fInput);
}
void SortSurname(people person[], int lenght)
{
	int i, j;
	people temp;

	for (i = 0; i < lenght; i++)
	{
		for (j = 0; j < lenght ; j++)
		{
			if (strcmp (person[i].surname, person[j].surname )< 0)
			{
				temp = person[i];
				person[i] = person[j];
				person[j] = temp;
			}
		}
	}
}
void PrintData(people person[], int lenght)
{
	int Class1Weight;
	for (int i = 0; i < lenght; i++)
	{
		printf("%ld %s %s %s ",person[i].id, person[i].name,person[i].surname, person[i].city);
		if (person[i].id /10000000000 == 3)
		{
			printf("\tMALE %ld.%ld.19%02ld Serial No.%03ld", person[i].id%1000000/10000
				,person[i].id%100000000/1000000,person[i].id%10000000000/100000000, person[i].id%10000/10);
		}
		else if (person[i].id /10000000000 == 5)
		{
			printf("\tMALE %ld.%ld.20%02ld Serial No.%03ld", person[i].id%1000000/10000
				,person[i].id%100000000/1000000,person[i].id%10000000000/100000000, person[i].id%10000/10);
		}
		else if ( person[i].id /10000000000 == 4)
		{
			printf("\tFEMALE %ld.%ld.19%02ld Serial No.%03ld", person[i].id%1000000/10000
				,person[i].id%100000000/1000000,person[i].id%10000000000/100000000, person[i].id%10000/10);
		}
		else if (person[i].id /10000000000 == 6)
		{
			printf("\tFEMALE %ld.%ld.20%02ld Serial No.%03ld", person[i].id%1000000/10000
				,person[i].id%100000000/1000000,person[i].id%10000000000/100000000, person[i].id%10000/10);
		}
		else
			printf("INVALID ID NUMBER!");
		
		Class1Weight = (1 * person[i].id / 10000000000%10 + 2 * person[i].id / 1000000000%10 
			+ 3 * person[i].id / 100000000%10 + 4 * person[i].id / 10000000%10 + 5 * person[i].id / 1000000%10
			+ 6 * person[i].id / 100000%10 + 7 * person[i].id / 10000%10 + 8 * person[i].id / 1000%10 + 9 * person[i].id / 100%10
			+ 1 * person[i].id / 10%10) % 11;
			printf(" %d", Class1Weight);
		printf("\n");
	}
}
void SearchNames(people person[], int lenght)
{
	unsigned option, i;
	int match = 0;
	char nameInput[LEN_NAME];
	while(1)
	{
		printf("\n\nSelect your action!\n\n");
        printf("1. Search People by their cities\n");
        printf("2. Exit\n");
        scanf("%u", &option);
        switch(option)
        {
			case 1:
				printf("Enter the name of the city\n");
				scanf("%s", nameInput);
				for (i = 0; i < lenght; i++)
				{
					if (strcasecmp(person[i].city, nameInput) == 0)
					{
						printf("%ld %s %s %s\n",person[i].id, person[i].name,person[i].surname, person[i].city);
						match = 1;
					}
				}
				if (match == 0)
				{
					printf("Nobody lives there!\n");
				}
				match = 0;
				break;
			case 2:
				exit(EXIT_SUCCESS);
			default:
				printf("Choose 1 or 2! \n");
		}
	}
}
int CheckCheckSum(long x)
{
	printf("this is a test %ld", x);
	
	return 0;
}
