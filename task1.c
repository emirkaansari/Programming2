#include <stdio.h>
#include <string.h>

#define STRING_MAX 100

void removeVowels(char oldString[]);
int check_vowel(char t);
int main(void)
{
	char oldString[] = "Good morning to you!";
	removeVowels(oldString);
	return 0;
}
void removeVowels(char oldString[])
{
	int j = 0;
	int i;
	
	char newString[STRING_MAX];
	
	for (i = 0; oldString[i] != '\0'; i++) 
	{
		if (check_vowel(oldString[i]) == 0) 
		{  
			newString[j] = oldString[i];
			j++;
		}
		else if(check_vowel(oldString[i]) == 2)
		{
			newString[j] = 'n';
			j++;
		}
		else if(check_vowel(oldString[i]) == 3)
		{
			newString[j] = 'm';
			j++;
		}
    }
  newString[j] = '\0';
  printf("String before deleting vowels: %s\n", oldString);
  printf("String after deleting vowels: %s\n", newString);



	
}
int check_vowel(char t)
{
  if (t == 'a' || t == 'A' || t == 'e' || t == 'E' || t =='o' || t=='O' || t == 'u' || t == 'U')
    return 1;
  else if (t == 'm' || t == 'M') 
	return 2;
  else if (t == 'n' || t == 'N')
	return 3;

  return 0;
}
