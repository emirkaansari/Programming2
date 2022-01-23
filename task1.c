#include <stdio.h>
#include <string.h>

#define STRING_MAX 100

void removeVowels(char oldString[]);
int check_vowel(char t);
int main(void)
{
	char oldString[] = "Calculus is really hard";
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
    }
  newString[j] = '\0';
  printf("String before deleting vowels: %s\n", oldString);
  printf("String after deleting vowels: %s\n", newString);



	
}
int check_vowel(char t)
{
  if (t == 'a' || t == 'A' || t == 'e' || t == 'E' || t == 'i' || t == 'I' || t =='o' || t=='O' || t == 'u' || t == 'U')
    return 1;

  return 0;
}
