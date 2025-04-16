#include <stdio.h>

int main(void)
{
	int x, v;
	printf("Enter value for x: ");
	scanf("%d", &x);
	v = ((((3 * x + 2)* x - 5) * x - 1) * x + 7) * x - 6;
	printf("%d\n", v);

	return 0;
}
