#include <stdio.h>

int main (void)
{
	double pi = 3.14;
	double *p = &pi;
	printf("%p\n", p); // same thing with 10th line.
	printf("%.2f\n", pi);
	printf("%p\n", &p); //& for location
	printf("%p\n", (void *)p); // use p for pointers
	printf("%lg\n", *p); //long double, no min max limit.
	
	return 0;
}
