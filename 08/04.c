#include <stdio.h>

#define N 10
#define S (int) (sizeof(a) / sizeof(a[0]))

int main(void)
{
	int a[N];
	printf("Enter 10 numbers: ");
	for (int i = 0; i < S; i++)
		scanf("%d", &a[i]);

	printf("Your numbers in reverse:");
	for (int i = S - 1; i >= 0; i--)
		printf(" %d", a[i]);

	printf("\n");
	return 0;
}
