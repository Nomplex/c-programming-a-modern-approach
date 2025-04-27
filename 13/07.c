#include <stdio.h>

int main(void)
{
	char *tens[] = {
		"", "Ten", "Twenty", "Thirty",
		"Fourty", "Fifty", "Sixty",
		"Seventy", "Eighty", "Ninety"
	};
	char *ones[] = {
		"", "-one", "-two", "-three",
		"-four", "-five", "-six",
		"-seven", "-eight", "-nine",
		"Eleven", "Twelve", "Thirteen",
		"Fourteen", "Fifteen", "Sixteen",
		"Seventeen", "Eighteen", "Nineteen"
	};

	int num, tensDigit, onesDigit;

	printf("Enter a two-digit number: ");
	scanf("%2d", &num);

	tensDigit = num / 10;
	onesDigit = num % 10;


	if (tensDigit == 1 && onesDigit != 0)
		printf("%s\n", ones[9 + onesDigit]);
	else
		printf("%s%s\n", tens[tensDigit], ones[onesDigit]);

	return 0;
}

