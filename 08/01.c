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

	printf("Repeated Digit(s):");
	for (int i = 0; i < 10; i++)
		if (nums[i] > 1)
			printf(" %d", i);

	printf("\n");
	return 0;
}
