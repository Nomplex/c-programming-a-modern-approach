#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void generate_random_walk(char matrix[10][10]);
void print_array(char matrix[10][10]);

int main(void)
{
	char matrix[SIZE][SIZE];

	srand((unsigned) time(NULL));

	generate_random_walk(matrix);
	print_array(matrix);

	return 0;
}

void generate_random_walk(char matrix[10][10])
{
	char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	int row = 0, col = 0, dir;

	// Fill Matrix
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			matrix[i][j] = '.';

	matrix[row][col] = 'A';
	for (int i = 1; i < 26; i++) {
		bool choice = false;
		bool option[4] = { true, true, true, true };

		do {
			dir = rand() % 4;

			if (!option[0] && !option[1] && !option[2] && !option[3]) {
				printf("No Moves for letter %c\n", alphabet[i]);
				return;
			}

			if (!option[dir])
				continue;

			option[dir] = false;
			switch(dir) {
				case 0: // UP
					if (row - 1 >= 0 && matrix[row-1][col] == '.') {
						row -= 1;
						choice = true;
					}
					break;
				case 1: // RIGHT
					if (col + 1 <= SIZE-1 && matrix[row][col+1] == '.') {
						col += 1;
						choice = true;
					}
					break;
				case 2: // DOWN
					if (row + 1 <= SIZE-1 && matrix[row+1][col] == '.') {
						row += 1;
						choice = true;
					}
					break;
				case 3: // LEFT
					if (col - 1 >= 0 && matrix[row][col-1] == '.') {
						col -= 1;
						choice = true;
					}
					break;
			}
		} while(!choice);
		matrix[row][col] = alphabet[i];
	}

	printf("Walk Completed Successfully!\n");
}

void print_array(char matrix[10][10])
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%c", matrix[i][j]);
		printf("\n");
	}
}

