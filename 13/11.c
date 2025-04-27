#include <stdio.h>

#define MAX 50

double compute_average_word_length(const char *sentence);

int main(void)
{
	char sentence[MAX+1];

	printf("Enter a sentence: ");
	fgets(sentence, MAX, stdin);

	printf("Average word length: %.1f\n", compute_average_word_length(sentence));
	return 0;
}

double compute_average_word_length(const char *sentence)
{
	int totalChars = 0, totalWords = 1;
	while (*sentence) {
		if (*sentence == ' ')
			totalWords++;
		else
			totalChars++;
		sentence++;
	}
	return (double) totalChars / totalWords;
}
