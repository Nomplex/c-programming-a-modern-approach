#include <stdio.h>

int main(void)
{
	int iNum, m, d, y;
	float uPrice;

	printf("Enter item number: ");
	scanf("%d", &iNum);

	printf("Enter unit price: ");
	scanf("%f", &uPrice);

	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &m, &d, &y);

	/* Not sure how to actually get the date to line up with it's title */
	/* when price is 9999.99 */
	printf("\nItem\t\tUnit\t\tPurchase");
	printf("\n\t\tPrice\t\tDate\n");
	printf("%d\t\t$%6.2f\t\t%.2d/%.2d/%.4d", iNum, uPrice, m, d, y);

	return 0;
}
