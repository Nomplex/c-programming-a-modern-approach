#include <stdio.h>

int main(void)
{
	float income, taxDue;
	printf("Enter your income: ");
	scanf("%f", &income);

	if (income < 750)
		taxDue = income * .01f;
	else if (income <= 2250.00f)
		taxDue = 7.50f + ((income - 750.00f) * .02f);
	else if (income <= 3750.00f)
		taxDue = 37.50f + ((income - 2250.00f) * .03f);
	else if (income <= 5250.00f)
		taxDue = 82.50f + ((income - 3750.00f) * .04f);
	else if (income <= 7000.00f)
		taxDue = 142.50f + ((income - 5250.00f) * .05f);
	else
		taxDue = 230.00f + ((income - 7000.00f) * .06f);

	printf("Tax due: $%.2f\n", taxDue);

	return 0;
}
