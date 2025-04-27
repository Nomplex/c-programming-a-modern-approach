#include <stdio.h>
#include <string.h>

#define MAX 20

int main(void)
{
	char word[MAX+1], smallest_word[MAX+1], largest_word[MAX+1];

	printf("Enter word: ");
	scanf("%s", word);
	strcpy(largest_word, strcpy(smallest_word, word));

	do {
		printf("Enter word: ");
		scanf("%s", word);
	
		if (strcmp(word, smallest_word) < 0)
			strcpy(smallest_word, word);
		else if (strcmp(word, largest_word) > 0)
			strcpy(largest_word, word);
	} while (strlen(word) != 4);

	printf("\nSmallest word: %s\n", smallest_word);
	printf("Largest word: %s\n", largest_word);

	return 0;
}
