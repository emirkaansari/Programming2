#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_READ 200
#define LEN_NAME 32

typedef struct people
{
	long id[MAX_READ];
	char name[MAX_READ][LEN_NAME];
	char surname[MAX_READ][LEN_NAME];
	char city[MAX_READ][LEN_NAME];
	
	
} people;

int main(void)
{
	
	FILE *fInput;
	char nameInput[LEN_NAME];
	int i, match = 0;
	char choice;
	people person;
	fInput = fopen("task1data.txt", "r");
	if(fInput == NULL)
	{
		printf("Error opening the file\n");
		exit(EXIT_FAILURE);	
	}
	for (i = 0; i < MAX_READ; i++)
	{
		fscanf(fInput,"%ld %s %s %s",&person.id[i], person.name[i],person.surname[i], person.city[i]);
	}
	
	for (i = 0; i < MAX_READ; i++)
	{
		printf("%ld %s %s %s\n",person.id[i], person.name[i],person.surname[i], person.city[i]);
	}
	printf("######################################################\n");
	
	do
	{
		printf("Enter a name of a city to view the peope from there\n");
		scanf("%s", nameInput);
		for (i = 0; i < MAX_READ; i++)
		{
			if (strcmp(person.city[i], nameInput) == 0)
			{
				printf("%ld %s %s %s\n",person.id[i], person.name[i],person.surname[i], person.city[i]);
				match = 1;
			}
		}
			if (match == 0)
			{
				printf("Nobody lives there!\n");
			}
			
			match = 0;

		printf("Would you like to continue to search people in cities? y for continue /n for exit \n");
		scanf(" %c", &choice);
	}
	while (choice == 'y' || choice == 'Y');
	
	fclose(fInput);
	return 0;
}
