#include <stdio.h>

#define MAX_WORD 30
#define MAX_LEN 20

int main(void)
{
	char word[MAX_WORD][MAX_LEN+1], term, ch;
	int row = 0, len = 0;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n') {
		if (ch == ' ' || len == MAX_LEN) {
			word[row][len] = '\0';
			row++;
			len = 0;
			continue;
		}

		if (ch == '.' || ch == '?' || ch == '!') {
			term = ch;
			break;
		}

		word[row][len++] = ch;
	}

	printf("Reversal of sentence: ");
	while (row > 0) {
		printf("%s ", word[row--]);
	}
	printf("%s%c\n", word[row], term);

	return 0;
}

