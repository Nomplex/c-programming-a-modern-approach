#include <stdio.h>

int main(void)
{
	int n, d;
	printf("Enter a three digit number: ");
	scanf("%d", &n);

	d = n % 100;
	printf("The reversal is: %d%d%d\n", d % 10, d / 10, n / 100);
	return 0;
}
