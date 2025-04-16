#include <stdio.h>

int main(void)
{
	int amount, twenty, ten, five;
	
	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	amount -= (twenty = amount / 20) * 20;
	amount -= (ten = amount / 10) * 10;
	amount -= (five = amount / 5) * 5;

	printf("$20 bills: %d\n", twenty);
	printf("$10 bills: %d\n", ten);
	printf("$5  bills: %d\n", five);
	printf("$1  bills: %d\n", amount);

	return 0;
}
