#include <stdio.h>

int main(void)
{
	int num, denom, gcd;
	printf("Enter a fraction (n/d): ");
	scanf("%d/%d", &num, &denom);

	for (int temp = 0, x = num, y = denom; x != 0; x = temp) {
		temp = y % x;
		y = x;
		gcd = y;
	}

	printf("In lowest terms: %d/%d\n", num / gcd, denom / gcd);
	return 0;
}
