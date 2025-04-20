#include <stdio.h>

int main(void)
{
	int nPayments;
	float balance, iRate, payment;

	printf("Enter amount of loan: ");
	scanf("%f", &balance);
	printf("Enter monthly interest rate: ");
	scanf("%f", &iRate);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);
	printf("Enter number of monthly payments: ");
	scanf("%d", &nPayments);

	iRate = (iRate / 100) / 12;

	for (int i = 0; i < nPayments && balance > 0; i++) {
		if ((balance = balance + (balance * iRate) - payment) < 0)
			balance = 0;
		printf("Balance remaining after payment %d: %.2f\n", i + 1, balance);
	}

	return 0;
}
