#include <math.h>
#include <stdio.h>

int main(void)
{
	double x, y = 1;
	printf("Enter a positive number: ");
	scanf("%lf", &x);

	while (fabs((y + x / y) / 2 -y) > .00001 * y)
		y = (y + x / y) / 2;

	printf("Square root: %.5f\n", y);
	return 0;
}
