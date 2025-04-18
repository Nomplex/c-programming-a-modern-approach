#include <stdio.h>

int main(void)
{
	int shares;
	float pricePerShare, value, commission, rivalCommission;

	printf("Enter the number of shares purchased: ");
	scanf("%d", &shares);
	printf("Enter the price per share: ");
	scanf("%f", &pricePerShare);

	value = shares * pricePerShare;

	if (value < 2500.00f)
		commission = 30.00f + .017f * value;
	else if (value < 6250.00f)
		commission = 56.00f + .0066f * value;
	else if (value < 20000.00f)
		commission = 76.00f + .0034f * value;
	else if (value < 50000.00f)
		commission = 100.00f + .0022f * value;
	else if (value < 500000.00f)
		commission = 155.00f + .0011f * value;
	else
		commission = 255.00f + .0009f * value;

	if (commission < 39.00f)
		commission = 39.00f;

	if (shares < 2000)
		rivalCommission = 33.00f + .03f * shares;
	else
		rivalCommission = 33.00f + .02f * shares;

	printf("Commission: $%.2f\n", commission);
	printf("Rival Commission: $%.2f\n", rivalCommission);

	return 0;
}
