#include <stdio.h>

int main(void)
{
	char sentence[50], ch, term;
	int size = 0;

	printf("Enter a sentence: ");
	while (size < 50 && (ch = getchar()) != '\n') {
		if (ch == '.' || ch == '?' || ch == '!') {
			term = ch;
			break;
		}
		sentence[size++] = ch;
	}
	
	printf("Reversal of sentence:");
	for (int p = size-1, q = size; p >= 0; p--) {
		if (sentence[p-1] == ' ' || p == 0) {
			printf(" ");
			for (int i = p; i < q; i++) {
				putchar(sentence[i]);
			}
			q = p-1;
		}
	}
	
	if (term)
		putchar(term);

	return 0;
}
