#include <stdio.h>
#include "quicksort.h"
#include "split.h"

#define N 10

int main(void)
{
	int a[N];

	printf("Enter %d numbers to be sorted: ", N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);

	quicksort(a, a + N - 1);

	printf("In sorted order: ");
	for (int i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}


