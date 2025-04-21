#include <stdio.h>

int main(void)
{
	int n;
	float e = 1.0f;

	printf("Enter integer n: ");
	scanf("%d", &n);

	for (int i = 1, d = 1; i <= n; i++)
		e += 1.0f / (d *= i);

	printf("Approximation of e: %f\n", e);
	return 0;
}
