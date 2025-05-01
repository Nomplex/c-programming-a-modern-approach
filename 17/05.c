#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARR 5
#define MAX_LEN 20

int read_line(char str[], int n);
int compare_string(const void *p, const void *q);

int main(void)
{
	char *words[MAX_ARR];
	char word[MAX_LEN+1];
	int wRead = 0;

	while (wRead < MAX_ARR) {
		int wLen = read_line(word, MAX_LEN+1);
		if (wLen == 0)
			break;
		words[wRead] = malloc(wLen * sizeof(char));
		strcpy(words[wRead++], word);
	}

	qsort(words, wRead, sizeof(char *), compare_string);

	for (int i = 0; i < wRead; i++) {
		printf("%s\n", words[i]);
	}

	return 0;
}

int read_line(char str[], int n)
{
	int ch, i = 0;

	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	str[i] = '\0';
	return i;
}

int compare_string(const void *p, const void *q)
{
	const char *s1 = *((const char**) p);
	const char *s2 = *((const char**) q);

	return strcmp(s1, s2);
}
