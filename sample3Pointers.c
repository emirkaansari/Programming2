#include <stdio.h>

void SetVal(int *val);

int main(void)
{
	int num = 0;
	SetVal(&num);
	printf("%d\n", num);
	return 0;
}

void SetVal(int *val)
{
	*val = 55;
}
