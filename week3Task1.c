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

typedef struct temporary
{
	long id;
	char name[LEN_NAME];
	char surname[LEN_NAME];
	char city[LEN_NAME];
} temporary;

int main(void)
{
	
	FILE *fInput;
	char nameInput[LEN_NAME];
	int i, j, match = 0;
	int frequency[MAX_READ] = {-1};
	
	int count;
	char choice;
	//char choice2;
	people person;
	temporary temp;
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
		for (j = 0; j < MAX_READ; j++)
		{
			if (strcmp(person.surname[i], person.surname[j]) < 0)
			{
				strcpy(temp.surname, person.surname[i]);
				strcpy(person.surname[i], person.surname[j]);
				strcpy(person.surname[j], temp.surname);
				
				strcpy(temp.name, person.name[i]);
				strcpy(person.name[i], person.name[j]);
				strcpy(person.name[j], temp.name);
								
				strcpy(temp.city, person.city[i]);
				strcpy(person.city[i], person.city[j]);
				strcpy(person.city[j], temp.city);
				
				temp.id = person.id[i];
				person.id[i] = person.id[j];
				person.id[j] = temp.id;
				
				
			}
		}
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
			if (strcasecmp(person.city[i], nameInput) == 0)
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
	
		for (i = 0; i < MAX_READ; i++)
		{
			count = 1;
			for (j = i + 1 ; j < MAX_READ; j++)
			{
				if (strcmp(person.city[i], person.city[j]) == 0)
				{
					count++;
					frequency[j] = 0; 
				}
			}
			if (frequency[i] != 0)
			{
				frequency[i] = count;
			}
		
		}

	
	for (i = 0; i < MAX_READ; i++)
	{
		if(frequency[i] != 0)
		{
			printf("%s occured %d time(s) \n", person.city[i], frequency[i]);
		}
		
	}
	fclose(fInput);
	return 0;
}
