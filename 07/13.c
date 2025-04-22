#include <stdio.h>

int main(void)
{
	char ch;
	int word = 1, len = 0;

	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n') {
		if (ch == ' ')
			word++;
		else
			len++;
	}

	printf("Average word length: %.1f\n", (float) len / word);
	return 0;
}
