#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#define SIZE 26

void read_word(int word[SIZE]);
bool equal_array(int wordOne[SIZE], int wordTwo[SIZE]);

int main(void)
{
	int wordOne[SIZE] = { 0 }, wordTwo[SIZE] = { 0 };

	printf("Enter first word: ");
	read_word(wordOne);

	printf("Enter second word: ");
	read_word(wordTwo);

	if (equal_array(wordOne, wordTwo))
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");

	return 0;
}

void read_word(int word[SIZE])
{
	char ch;

	while((ch = getchar()) != '\n') {
		if (isalpha(ch)) word[toupper(ch) - 'A']++;
	}
}

bool equal_array(int wordOne[SIZE], int wordTwo[SIZE])
{
	for (int i = 0; i < 26; i++) {
		if (wordOne[i] != wordTwo[i])
			return false;
	}

	return true;
}
