#include <stdio.h>

int main(void)
{
	int nums[10] = { 0 };
	long num;

	do {
		printf("Enter a number (0 to exit): ");
		scanf("%ld", &num);
		if (num <= 0)
			break;

		while (num > 0) {
			nums[num % 10]++;
			num /= 10;
		}

		printf("Digits:\t");
		for (int i = 0; i < 10; i++)
			printf("\t%d", i);

		printf("\nOccurrences:");
		for (int i = 0; i < 10; i++) {
			printf("\t%d", nums[i]);
			nums[i] = 0;
		}

		printf("\n");
	} while (1);
	return 0;
}
