#include <stdio.h>

int main(void)
{
	float balance, iRate, payment;

	printf("Enter amount of loan: ");
	scanf("%f", &balance);
	printf("Enter monthly interest rate: ");
	scanf("%f", &iRate);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);

	iRate = (iRate / 100) / 12;

	/* I could definitely do this cleaner but I thought it was pretty cool that this was possible */
	printf("Balance remaining after first payment: $%.2f\n", (balance = balance + (balance * iRate) - payment));
	printf("Balance remaining after second payment: $%.2f\n", (balance = balance + (balance * iRate) - payment));
	printf("Balance remaining after third payment: $%.2f\n", (balance = balance + (balance * iRate) - payment));

	return 0;
}
