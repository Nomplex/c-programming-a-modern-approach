#include <stdio.h>

int main(void)
{
	int x, fac;

	printf("Enter a positive integer: ");
	scanf("%d", &x);
	fac = x;
	for (int i = fac - 1; i > 1; i--)
		fac *= i;

	printf("Factorial of %d: %d\n", x, fac);
	return 0;
}
