#include <ctype.h>
#include <stdio.h>

#define MAX 50

int compute_vowel_count(const char *sentence);

int main(void)
{
	char sentence[MAX + 1], *p = sentence, ch;

	printf("Enter a sentence: ");
	while (p < sentence + MAX && (ch = getchar()) != '\n')
		*p++ = ch;
	*p = '\0';

	printf("Your sentence contains %d vowels.\n", compute_vowel_count(sentence));
	return 0;
}

int compute_vowel_count(const char *sentence)
{
	int count = 0;
	while (*sentence) {
		switch (toupper(*sentence)) {
			case 'A': case 'E': case 'I':
			case 'O': case 'U':
				count++;
			break;
		}
		sentence++;
	}
	return count;
}

