#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_LEN 20

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
	char word1[MAX_LEN+1], word2[MAX_LEN+1], ch;

	printf("Enter first word: ");
	for (char *p = word1; p < word1 + MAX_LEN; p++) {
		if ((ch = getchar()) == '\n')
			break;
		*p = ch;
	}

	printf("Enter second word: ");
	for (char *p = word2; p < word2 + MAX_LEN; p++) {
		if ((ch = getchar()) != '\n')
			break;
		*p = ch;
	}

	if (are_anagrams(word1, word2))
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");

	return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
	int alpha[26] = { 0 };
	while (*word1) {
		if (isalpha(*word1)) alpha[toupper(*word1) - 'A']++;
		word1++;
	}

	while (*word2) {
		if (isalpha(*word1)) alpha[toupper(*word1) - 'A']--;
		word1++;
	}

	for (int *i = alpha; *i; i++)
		if (*i != 0)
			return false;
	return true;
}
