#include <stdio.h>

int polynomial(int n);

int main(void)
{
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);
	printf("Polynomial: %d\n", polynomial(num));

	return 0;
}

int polynomial(int n)
{
	return ((((3 * n + 2) * n - 5) * n - 1) * n + 7) * n - 6;
}
