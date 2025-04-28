#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX 30

bool is_palindrome(const char *message);

int main(void)
{
	char message[MAX+1], *p = message, ch;

	printf("Enter a word: ");
	while (p < message + MAX && (ch = getchar()) != '\n')
		if (isalpha(ch))
			*p++ = toupper(ch);
	*p = '\0';

	if (is_palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");

	return 0;
}

bool is_palindrome(const char *message)
{
	const char *p = message, *q = message;
	while (*q)
		q++;
	q--;

	while (p < q) {
		if (*p != *q)
			return false;
		p++;
		q--;
	}

	return true;
}
