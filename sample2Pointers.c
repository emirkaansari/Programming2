#include <stdio.h>

int main (void)
{
	int num;
	int *p;
	p = &num;
	scanf("%d", p);
	printf("%d\n", *p);
	*p = 55;
	printf("%d\n", num);
	
	return 0;
}
