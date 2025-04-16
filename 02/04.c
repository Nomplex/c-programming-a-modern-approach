#include <stdio.h>

int main(void)
{
	float amount;
	printf("Enter an amount: ");
	scanf("%f", &amount);

	/* I suppose we could also use `amount * 1.05` instead */
	printf("With tax added: %.2f", amount + (amount * 0.05));

	return 0;
}
