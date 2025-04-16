#include <stdio.h>

int main(void)
{
	int x, v;
	printf("Enter value for x: ");
	scanf("%d", &x);
	v = 3 * (x * x * x * x * x) + 2 * (x * x * x * x) - 5 * (x * x * x) - x * x + 7 * x - 6;
	printf("%d\n", v);

	return 0;
}
