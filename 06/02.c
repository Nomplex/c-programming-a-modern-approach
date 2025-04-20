#include <stdio.h>

int main(void)
{

	int x, y;
	printf("Enter two integers: ");
	scanf("%d %d", &x, &y);

	for (int temp = 0; x != 0; x = temp) {
		temp = y % x;
		y = x;
	}

	printf("Greatest common divisor: %d\n", y);
	return 0;
}
