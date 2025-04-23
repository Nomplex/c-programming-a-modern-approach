#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int alphaValue[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 }, total = 0;

	printf("Enter a word: ");
	while ((ch = toupper(getchar())) != '\n') {
		if (ch >= 'A' && ch <= 'Z')
			total += alphaValue[ch - 'A'];
	}

	printf("Scrabble value: %d\n", total);
	return 0;
}
