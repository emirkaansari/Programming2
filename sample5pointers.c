#include <stdio.h>

int main(void)
{
    int i;
    int ints[] = {1, 2, 3, 4, 5};
    char chars[] = {"abcde"};
    short shorts[] = {1, 2, 3, 4, 5};
    double doubles[] = {1.1, 1.2, 1.3, 1.4, 1.5};
    
    int *pInt = ints;
    char *pChar = chars;
    short *pShort = shorts;
    double *pDouble = doubles;
    
    for (i = 0; i < 5; i++, pInt++, pChar++, pShort++, pDouble++)
    {
        printf("%c @ %p \t", *pChar, (void *)pChar);
        printf("%hd @ %p \t", *pShort, (void *)pShort);
        printf("%d @ %p \t", *pInt, (void *)pInt);
        printf("%.1lf @ %p\n", *pDouble, (void *)pDouble);
    }
    return 0;

}
