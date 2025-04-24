#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char ch;
	int alpha[26] = { 0 };

	printf("Enter first word: ");
	while((ch = getchar()) != '\n') {
		if (isalpha(ch)) alpha[toupper(ch) - 'A']++;
	}

	printf("Enter second word: ");
	while((ch = getchar()) != '\n') {
		if (isalpha(ch)) alpha[toupper(ch) - 'A']--;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] != 0) {
			printf("The words are not anagrams.");
			return 0;
		}
	}

	printf("The words are anagrams.\n");
	return 0;
}
