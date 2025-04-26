#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITS 10

// Instead of clockwise it goes row wise, left to right
// digits 0 through 9
int segments[10][7] = {
			{ 1, 1, 0, 1, 1, 1, 1 },
			{ 0, 0, 0, 1, 0, 0, 1 },
			{ 1, 0, 1, 1, 1, 1, 0 },
			{ 1, 0, 1, 1, 0, 1, 1 },
			{ 0, 1, 1, 1, 0, 0, 1 },
			{ 1, 1, 1, 0, 0, 1, 1 },
			{ 1, 1, 1, 0, 1, 1, 1 },
			{ 1, 0, 0, 1, 0, 0, 1 },
			{ 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 1, 1, 1, 0, 1, 1 }};

// Digits are 3 characters wide but need a column of space between them.
// [row][col]
char digits[3][MAX_DIGITS * 4];

void clearDigitsArray(void);
void processDigit(int digit, int position);
void printDigitsArray(void);

int main(void)
{
	char ch;
	int arr[MAX_DIGITS], len = 0;

	printf("Enter a number: ");
	while (len < MAX_DIGITS && (ch = getchar()) != '\n')
		if (ch >= 48 && ch <= 57)
			arr[len++] = ch - '0';

	clearDigitsArray();
	for (int i = 0; i < len; i++)
		processDigit(arr[i], i);
	printDigitsArray();

	return 0;
}

void clearDigitsArray(void)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++)
			digits[i][j] = ' ';
	}
}

void processDigit(int digit, int position)
{
	int i = 0, starting = position * 4;
	for (int row = 0; row < 3; row++) {
		for (int col = starting; col < starting + 3; col++) {
			if (col % 2 == 1) 
				segments[digit][i++] ? digits[row][col] = '_' : ' ';
			else if (row == 1 || row == 2)
				segments[digit][i++] ? digits[row][col] = '|' : ' ';
		}
	}
}

void printDigitsArray(void)
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < MAX_DIGITS * 4; j++)
			printf("%c", digits[i][j]);
		printf("\n");
	}
}

