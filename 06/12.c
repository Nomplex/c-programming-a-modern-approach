#include <stdio.h>

int main(void)
{
	float ep, e = 1.0f, term = 1.0f;

	printf("Enter ep: ");
	scanf("%f", &ep);

	for (int i = 1, d = 1; term > e; i++) {
		term = (1.0f / (d *= i));
		e += term;
	}
	printf("Approximation of e: %f\n", e);

	return 0;
}
