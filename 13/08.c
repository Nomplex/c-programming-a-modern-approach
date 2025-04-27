
#include <ctype.h>
#include <stdio.h>

int compute_scrabble_value(const char *word);

int main(void)
{
	char word[50+1], *p = word, ch;

	printf("Enter a word: ");
	while (p < word + 50 - 1 && (ch = getchar()) != '\n')
		*p++ = ch;
	*p++ = '\0';

	printf("Scrabble value: %d\n", compute_scrabble_value(word));
	return 0;
}

int compute_scrabble_value(const char *word)
{
	int total = 0, cValue[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
	for (const char *p = word; *p; p++) {
		total += cValue[toupper(*p) - 'A'];
	}
	return total;
}
