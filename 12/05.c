#include <stdio.h>

int main(void)
{
	char sentence[50], *len = sentence, ch, term;

	printf("Enter a sentence: ");
	while (len < sentence + 50 && (ch = getchar()) != '\n') {
		if (ch == '.' || ch == '?' || ch == '!') {
			term = ch;
			break;
		}
		*len++ = ch;
	}

	printf("Reversal of sentence:");
	for (char *p = len - 1, *q = len; p >= sentence; p--) {
		if (*(p-1) == ' ' || p == sentence) {
			printf(" ");
			for (char *i = p; i < q; i++) {
				putchar(*i);
			}
			q = p-1;
		}
	}

	if (term)
		putchar(term);
	putchar('\n');

	return 0;
}

