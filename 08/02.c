
#include <stdio.h>

int main(void)
{
	int nums[10] = { 0 };
	long num;
	printf("Enter a number: ");
	scanf("%ld", &num);

	while (num > 0) {
		nums[num % 10]++;
		num /= 10;
	}

	printf("Digits:\t");
	for (int i = 0; i < 10; i++)
		printf("\t%d", i);

	printf("\nOccurrences:");
	for (int i = 0; i < 10; i++)
		printf("\t%d", nums[i]);

	printf("\n");
	return 0;
}
