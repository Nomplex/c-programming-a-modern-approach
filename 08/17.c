#include <stdio.h>

int main(void)
{
	int size;

	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic square: ");
	scanf("%d", &size);

	if (size % 2 == 0) {
		printf("Not an odd number\n");
		return 1;
	}

	int matrix[size][size], row = 0, col = size / 2;

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}

	for(int i = 0; i < size * size; i++) {
		matrix[row][col] = i + 1;
		row = row - 1 < 0 ? size - 1 : row - 1;
		col = (col + 1) % size;

		if (matrix[row][col] != 0) {
			/*row = size + (i % size);*/
			row = (row + 2) % size;
			col = col - 1 < 0 ? size - 1 : col - 1;
		}

	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
