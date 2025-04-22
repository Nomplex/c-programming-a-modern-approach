#include <stdio.h>

#define SIZE 5

int main(void)
{
	/* A 2d array would probably be better. I think way is cool though */
	int rowSums[SIZE] = { 0 }, colSums[SIZE] = { 0 }, n[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
		printf("Enter row %d: ", i + 1);
		scanf("%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &n[4]);

		for (int j = 0; j < SIZE; j++)
			rowSums[i] += n[j];

		for (int j = 0; j < SIZE; j++)
			colSums[j] += n[j];
	}

	printf("\nRow totals:");
	for (int i = 0; i < SIZE; i++)
		printf(" %d", rowSums[i]);

	printf("\nColumn totals:");
	for (int i = 0; i < SIZE; i++)
		printf(" %d", colSums[i]);

	printf("\n");
	return 0;
}
